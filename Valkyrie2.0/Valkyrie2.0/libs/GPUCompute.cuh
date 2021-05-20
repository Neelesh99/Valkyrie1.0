#include "cuda_runtime.h"
#include <stdio.h>
#include "cuComplex.h"
#include "BaseTypes.h"

/*
	GPUCompute.cuh
	Description: Library of GPU specific functions needed to parallelise gate calculations

	Functions defined:
	matrixMul
	svMatrixMul
	svMatrixUltraMul
	svAddLargeScale
	convertQubitComplex
	convertComplexQubit
	tensorProduct
	calculateGPU2x2
	calculateGPU4x4
	calculateGPU
	calculateGPU2x2
	calculateGPU4x4
	calculateGPULargeSV
	calculateGPUSV
*/

namespace ValkGPULib {

	// matrixMul is GPU code for fast compute mode parallel row computation
	__global__ void matrixMul(cuDoubleComplex* output, const cuDoubleComplex* input, const cuDoubleComplex* gate, const int m) {
		int loc = threadIdx.x;
		output[loc] = make_cuDoubleComplex(0, 0);
		for (int i = 0; i < m; i++) {
			output[loc] = cuCadd(cuCmul(input[i], gate[m * loc + i]), output[loc]);
		}
	}

	// svMatrixMul is GPU code for statevector compute mode parallel row computation
	__global__ void svMatrixMul(cuDoubleComplex* output, const cuDoubleComplex* input, const cuDoubleComplex* gate, int m){
		int loc = blockIdx.x * blockDim.x + threadIdx.x;
		output[loc] = make_cuDoubleComplex(0, 0);
		for (int i = 0; i < m; i++) {			
			output[loc] = cuCadd(cuCmul(input[i], gate[m * loc + i]), output[loc]);
		}
	}

	// svMatrixUltraMul is GPU code for massively parallel large scale computation
	__global__ void svMatrixUltraMul(cuDoubleComplex* output, const cuDoubleComplex* input, const cuDoubleComplex* gate, int m) {
		int loc = blockIdx.x * blockDim.x + threadIdx.x;
		output[loc] = cuCmul(input[loc % m], gate[loc]);
	}

	// svAddLargeScale provides the summation of the temporary calculations provided by the svMatrixUltraMul
	__global__ void svAddLargeScale(cuDoubleComplex* output, cuDoubleComplex* input, int m) {
		int loc = threadIdx.x;
		output[loc] = make_cuDoubleComplex(0, 0);
		for (int i = 0; i < m; i++) {
			output[loc] = cuCadd(output[loc], input[m * loc + i]);
		} 
	}

	// convertQubitComplex converts  representation C++ stlib complex number into CUDA Complex number representation
	cuDoubleComplex convertQubitComplex(std::complex<double> input) {
		return make_cuDoubleComplex(input.real(), input.imag());
	}

	// convertQubitComplex converts CUDA Complex number representation into C++ stlib complex number representation
	std::complex<double> convertComplexQubit(cuDoubleComplex input) {
		return std::complex<double>(input.x, input.y);
	}

	// tensorProduct calculates tensor product values for fast compute mode
	cuDoubleComplex tensorProduct(std::vector<Qubit*> inputQubits, int i) {
		Qubit* qubit1 = inputQubits[0];
		Qubit* qubit2 = inputQubits[1];
		std::complex<double> result = *qubit1->fetch(i / 2) * *qubit2->fetch(i % 2);
		return make_cuDoubleComplex(result.real(), result.imag());
	}

	std::vector<std::complex<double>> calculateGPU2x2(cuDoubleComplex* beforeGate, cuDoubleComplex* gateValues, cuDoubleComplex* afterGate, Gate* gate, std::vector<Qubit*> qubits, int m, int n);

	std::vector<std::complex<double>> calculateGPU4x4(cuDoubleComplex* beforeGate, cuDoubleComplex* gateValues, cuDoubleComplex* afterGate, Gate* gate, std::vector<Qubit*> qubits, int m, int n);

	// calculateGPU is the overall calling function for fast compute mode
	std::vector<std::complex<double>> calculateGPU(cuDoubleComplex* beforeGate, cuDoubleComplex* gateValues, cuDoubleComplex* afterGate, Gate* gate, std::vector<Qubit*> qubits) {
		int m = gate->getM();
		int n = gate->getN();
		int qubitN = m / 2;

		cudaError_t cudaStatus;		

		// Generate Host side arrays for qubit values
		std::vector<std::complex<double>> results;
		if (m == 2) {
			results = calculateGPU2x2(beforeGate, gateValues, afterGate, gate, qubits, m, n);
		}
		else if (m == 4) {
			results = calculateGPU4x4(beforeGate, gateValues, afterGate, gate, qubits, m, n);			
		}
		return results;
	}

	// calculateGPU2x2 allows for single qubit gate parallelisation for fast compute mode
	std::vector<std::complex<double>> calculateGPU2x2(cuDoubleComplex* beforeGate, cuDoubleComplex* gateValues, cuDoubleComplex* afterGate, Gate* gate, std::vector<Qubit*> qubits, int m, int n){
		const int arraySize = 2;
		const cuDoubleComplex before[arraySize] = { convertQubitComplex(*(qubits[0]->fetch(0))), convertQubitComplex(*qubits[0]->fetch(1)) };
		const cuDoubleComplex gateVal[4] = { convertQubitComplex(gate->fetchValue(0,0)), convertQubitComplex(gate->fetchValue(0,1)), convertQubitComplex(gate->fetchValue(1,0)), convertQubitComplex(gate->fetchValue(1,1)) };
		cuDoubleComplex after[arraySize] = { 0 };
		cudaError_t cudaStatus;
		std::vector<std::complex<double>> forStateVector;
		// Copy input vectors into CUDA memory
		cudaStatus = cudaMemcpy(beforeGate, before, m * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			goto Error;
		}
		cudaStatus = cudaMemcpy(gateValues, gateVal, (m * n) * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			goto Error;
		}
		cudaStatus = cudaMemcpy(afterGate, after, m * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			goto Error;
		}

		// Run matrix calc kernel
		ValkGPULib::matrixMul << <1, 2 >> > (afterGate, beforeGate, gateValues, 2);

		// Check for any errors launching the kernel
		cudaStatus = cudaGetLastError();
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
			goto Error;
		}

		// cudaDeviceSynchronize waits for the kernel to finish, and returns
		// any errors encountered during the launch.
		cudaStatus = cudaDeviceSynchronize();
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
			goto Error;
		}

		// Copy output vector from GPU buffer to host memory.
		cudaStatus = cudaMemcpy(after, afterGate, m * sizeof(cuDoubleComplex), cudaMemcpyDeviceToHost);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			goto Error;
		}
		Qubit* qubit = qubits[0];
		*qubit->fetch(0) = convertComplexQubit(after[0]);
		*qubit->fetch(1) = convertComplexQubit(after[1]);
		forStateVector = { convertComplexQubit(after[0]), convertComplexQubit(after[1]) };
		return forStateVector;
	Error:
		return std::vector<std::complex<double>>();
	}

	// calculateGPU4x4 allows for double qubit gate parallelisation for fast compute mode
	std::vector<std::complex<double>> calculateGPU4x4(cuDoubleComplex* beforeGate, cuDoubleComplex* gateValues, cuDoubleComplex* afterGate, Gate* gate, std::vector<Qubit*> qubits, int m, int n) {
		const int arraySize = 4;
		const cuDoubleComplex before[arraySize] = { tensorProduct(qubits, 0), tensorProduct(qubits, 1) , tensorProduct(qubits, 2), tensorProduct(qubits, 3) };
		const cuDoubleComplex gateVal[16] = {
			convertQubitComplex(gate->fetchValue(0,0)), convertQubitComplex(gate->fetchValue(0,1)), convertQubitComplex(gate->fetchValue(0,2)), convertQubitComplex(gate->fetchValue(0,3)),
			convertQubitComplex(gate->fetchValue(1,0)), convertQubitComplex(gate->fetchValue(1,1)), convertQubitComplex(gate->fetchValue(1,2)), convertQubitComplex(gate->fetchValue(1,3)),
			convertQubitComplex(gate->fetchValue(2,0)), convertQubitComplex(gate->fetchValue(2,1)), convertQubitComplex(gate->fetchValue(2,2)), convertQubitComplex(gate->fetchValue(2,3)),
			convertQubitComplex(gate->fetchValue(3,0)), convertQubitComplex(gate->fetchValue(3,1)), convertQubitComplex(gate->fetchValue(3,2)), convertQubitComplex(gate->fetchValue(3,3)),
		};
		cuDoubleComplex after[arraySize] = { 0 };
		cudaError_t cudaStatus;
		// Copy input vectors into CUDA memory
		cudaStatus = cudaMemcpy(beforeGate, before, m * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}
		cudaStatus = cudaMemcpy(gateValues, gateVal, (m * n) * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}
		cudaStatus = cudaMemcpy(afterGate, after, m * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}

		// Run matrix calc kernel
		ValkGPULib::matrixMul << <1, 4 >> > (afterGate, beforeGate, gateValues, 4);

		// Check for any errors launching the kernel
		cudaStatus = cudaGetLastError();
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
			return std::vector<std::complex<double>>();
		}

		// cudaDeviceSynchronize waits for the kernel to finish, and returns
		// any errors encountered during the launch.
		cudaStatus = cudaDeviceSynchronize();
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
			return std::vector<std::complex<double>>();
		}

		// Copy output vector from GPU buffer to host memory.
		cudaStatus = cudaMemcpy(after, afterGate, m * sizeof(cuDoubleComplex), cudaMemcpyDeviceToHost);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}
		Qubit* qubit = qubits[0];
		*qubit->fetch(0) = convertComplexQubit(after[0]) + convertComplexQubit(after[1]);
		*qubit->fetch(1) = convertComplexQubit(after[2]) + convertComplexQubit(after[3]);
		qubit = qubits[1];
		*qubit->fetch(0) = convertComplexQubit(after[0]) + convertComplexQubit(after[2]);
		*qubit->fetch(1) = convertComplexQubit(after[1]) + convertComplexQubit(after[3]);
		std::vector<std::complex<double>> forStateVector = { convertComplexQubit(after[0]), convertComplexQubit(after[1]), convertComplexQubit(after[2]), convertComplexQubit(after[3]) };
		return forStateVector;
	}

	/// State Vector compute mode ///

	// calculateGPULargeSV allows for large size statevector -- gate multiplication to be entirely parallelised
	std::vector<std::complex<double>> calculateGPULargeSV(cuDoubleComplex* beforeGate, cuDoubleComplex* gateValues, cuDoubleComplex* afterGate, StateVector* reordered, std::vector<std::vector<std::complex<double>>> gateValuesV) {
		int arraySize = gateValuesV.size();
		cuDoubleComplex* before = new cuDoubleComplex[arraySize];
		cuDoubleComplex* gateVal = new cuDoubleComplex[arraySize * arraySize];
		cuDoubleComplex* after = new cuDoubleComplex[arraySize];

		std::vector<std::complex<double>> currentState = reordered->getState();
		for (int i = 0; i < currentState.size(); i++) {
			before[i] = convertQubitComplex(currentState[i]);
		}
		for (int i = 0; i < arraySize; i++) {
			for (int j = 0; j < arraySize; j++) {
				gateVal[i * arraySize + j] = convertQubitComplex(gateValuesV[i][j]);
			}
		}
		// Copy input vectors into CUDA memory
		cudaError_t cudaStatus;
		cudaStatus = cudaMemcpy(beforeGate, before, arraySize * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}
		cudaStatus = cudaMemcpy(gateValues, gateVal, (arraySize * arraySize) * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}
		cudaStatus = cudaMemcpy(afterGate, after, arraySize * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}
		cuDoubleComplex* tempOutput;
		cudaStatus = cudaMalloc((void**)&tempOutput, arraySize*arraySize* sizeof(cuDoubleComplex));
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMalloc failed!");
			return std::vector<std::complex<double>>();
		}
		int blockSize = 256;
		int numBlocks = (arraySize*arraySize + blockSize - 1) / blockSize;
		ValkGPULib::svMatrixUltraMul << <numBlocks, blockSize >> > (tempOutput, beforeGate, gateValues, arraySize);
		// Check for any errors launching the kernel
		cudaStatus = cudaGetLastError();
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
			return std::vector<std::complex<double>>();
		}

		// cudaDeviceSynchronize waits for the kernel to finish, and returns
		// any errors encountered during the launch.
		cudaStatus = cudaDeviceSynchronize();
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
			return std::vector<std::complex<double>>();
		}
		ValkGPULib::svAddLargeScale << <1, arraySize >> > (afterGate, tempOutput, arraySize);
		// Check for any errors launching the kernel
		cudaStatus = cudaGetLastError();
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
			return std::vector<std::complex<double>>();
		}

		// cudaDeviceSynchronize waits for the kernel to finish, and returns
		// any errors encountered during the launch.
		cudaStatus = cudaDeviceSynchronize();
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
			return std::vector<std::complex<double>>();
		}

		// Copy output vector from GPU buffer to host memory.
		cudaStatus = cudaMemcpy(after, afterGate, arraySize * sizeof(cuDoubleComplex), cudaMemcpyDeviceToHost);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}
		cudaFree(tempOutput);
		std::vector<std::complex<double>> output;
		for (int i = 0; i < arraySize; i++) {
			output.push_back(convertComplexQubit(after[i]));
		}
		return output;
	}

	// calculateGPUSV allows for small to medium statevectors to be easily parallelised
	std::vector<std::complex<double>> calculateGPUSV(cuDoubleComplex* beforeGate, cuDoubleComplex* gateValues, cuDoubleComplex* afterGate, StateVector* reordered, std::vector<std::vector<std::complex<double>>> gateValuesV) {
		int arraySize = gateValuesV.size();
		cuDoubleComplex* before = new cuDoubleComplex[arraySize];
		cuDoubleComplex* gateVal = new cuDoubleComplex[arraySize * arraySize];
		cuDoubleComplex* after = new cuDoubleComplex[arraySize];

		std::vector<std::complex<double>> currentState = reordered->getState();
		for (int i = 0; i < currentState.size(); i++) {
			before[i] = convertQubitComplex(currentState[i]);
		}
		for (int i = 0; i < arraySize; i++) {
			for (int j = 0; j < arraySize; j++) {
				gateVal[i * arraySize + j] = convertQubitComplex(gateValuesV[i][j]);
			}
		}
		// Copy input vectors into CUDA memory
		cudaError_t cudaStatus;
		cudaStatus = cudaMemcpy(beforeGate, before, arraySize * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}
		cudaStatus = cudaMemcpy(gateValues, gateVal, (arraySize * arraySize) * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}
		cudaStatus = cudaMemcpy(afterGate, after, arraySize * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}
		if (arraySize > 256) {
			int blockSize = 256;
			int numBlocks = (arraySize + blockSize - 1) / blockSize;
			ValkGPULib::svMatrixMul << <numBlocks, blockSize >> > (afterGate, beforeGate, gateValues, arraySize);
		}
		else {
			ValkGPULib::svMatrixMul << <1, arraySize >> > (afterGate, beforeGate, gateValues, arraySize);
		}
		// Check for any errors launching the kernel
		cudaStatus = cudaGetLastError();
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
			return std::vector<std::complex<double>>();
		}

		// cudaDeviceSynchronize waits for the kernel to finish, and returns
		// any errors encountered during the launch.
		cudaStatus = cudaDeviceSynchronize();
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
			return std::vector<std::complex<double>>();
		}

		// Copy output vector from GPU buffer to host memory.
		cudaStatus = cudaMemcpy(after, afterGate, arraySize * sizeof(cuDoubleComplex), cudaMemcpyDeviceToHost);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			return std::vector<std::complex<double>>();
		}
		std::vector<std::complex<double>> output;
		for (int i = 0; i < arraySize; i++) {
			output.push_back(convertComplexQubit(after[i]));
		}
		return output;
	}

}


