#include "GPUDevice.cuh"
#include "cuComplex.h"
#include <cmath>
#include <stdio.h>
#include "GPUCompute.cuh"

using namespace std::complex_literals;
const double ROOT2INV = 1.0 / std::pow(2, 0.5);

std::vector<std::vector<std::complex<double>>> getGateMatrixGPU(GateRequestType gateType) {
	switch (gateType) {
	case I:
		return std::vector<std::vector<std::complex<double>>> { {1, 0}, { 0, 1 } };
		break;
	case h:
		return std::vector<std::vector<std::complex<double>>> { {ROOT2INV, ROOT2INV}, { ROOT2INV, -1.0 * ROOT2INV } };
		break;
	case cx:
		return std::vector<std::vector<std::complex<double>>> { {1, 0, 0, 0}, { 0, 1, 0, 0 }, { 0, 0, 0, 1 }, { 0, 0, 1, 0 } };
		break;
	}
}

cuDoubleComplex convertQubitComplex(std::complex<double> input) {
	return make_cuDoubleComplex(input.real(), input.imag());
}

std::complex<double> convertComplexQubit(cuDoubleComplex input) {
	return std::complex<double>(input.x, input.y);
}

cuDoubleComplex tensorProduct(std::vector<Qubit*> inputQubits, int i) {
	Qubit* qubit1 = inputQubits[0];
	Qubit* qubit2 = inputQubits[1];
	std::complex<double> result = *qubit1->fetch(i / 2) * *qubit2->fetch(i % 2);
	return make_cuDoubleComplex(result.real(), result.imag());
}


Qubit* GPUQubitFactory::generateQubit()
{
	// Allocate heap memory for Qubit values
	std::complex<double>* s0 = new std::complex<double>;
	std::complex<double>* s1 = new std::complex<double>;
	*s0 = 1.0;
	*s1 = 0.0;
	// Allocate heap memory for Qubit and store values
	Qubit* generatedQubit = new Qubit(s0, s1);
	// Push into qubit tracker for deletion
	qubits_.push_back(generatedQubit);

	return generatedQubit;
}

GPUQubitFactory::~GPUQubitFactory()
{
	for (auto qubit : qubits_) {
		delete qubit->fetch(0);
		delete qubit->fetch(1);
		delete qubit;
	}
}

Gate* GPUGateFactory::generateGate(GateRequest request)
{
	std::vector<std::vector<std::complex<double>>> gateMatrix = getGateMatrixGPU(request.getGateType());
	int gateM = gateMatrix.size();
	int gateN = gateMatrix[0].size();

	Gate* generatedGate = new Gate(gateM, gateN, gateMatrix);
	gates_.push_back(generatedGate);
	return generatedGate;
}

GPUGateFactory::~GPUGateFactory()
{
	for (auto gate : gates_) {
		delete gate;
	}
}

void GPUQuantumCircuit::loadQubitMap(std::map<std::string, std::vector<Qubit*>> qubitMap)
{
	qubitMap_ = qubitMap;
}

void GPUQuantumCircuit::loadBlock(ConcurrentBlock block)
{
	std::vector<GateRequest> gates = block.getGates();
	std::vector<Calculation> calcs;
	for (auto gate : gates) {
		std::vector<std::string> registers = gate.getRegisters();
		std::vector<int> locations = gate.getLocations();
		std::vector<Qubit*> qubitValues;
		for (int i = 0; i < registers.size(); i++) {
			qubitValues.push_back(qubitMap_[registers[i]][locations[i]]);
		}
		Gate* gateTrue = gateFactory_->generateGate(gate);
		Calculation calc = Calculation(gateTrue, qubitValues);
		calcs.push_back(calc);
	}
	calculations_.push_back(calcs);
}

std::vector<Calculation> GPUQuantumCircuit::getNextCalculation()
{
	if (calcCounter == calculations_.size() - 1) {
		done_ = true;
		return calculations_[calcCounter];
	}
	else {
		std::vector<Calculation> val = calculations_[calcCounter];
		calcCounter++;
		return val;
	}
}

std::map<std::string, std::vector<Qubit*>> GPUQuantumCircuit::returnResults()
{
	return qubitMap_;
}

bool GPUQuantumCircuit::checkComplete()
{
	if (calculations_.size() == 0) {
		return true;
	}
	return done_;
}

void GPUQuantumProcessor::loadCircuit(AbstractQuantumCircuit* circuit)
{
	circuit_ = circuit;
}

void GPUQuantumProcessor::calculate()
{
	// Generate initial arrays
	cuDoubleComplex* initialValues;
	cuDoubleComplex* beforeGate;
	cuDoubleComplex* gateValues;
	cuDoubleComplex* afterGate;
	while (!circuit_->checkComplete()) {
		std::vector<Calculation> calcBlock = circuit_->getNextCalculation();
		for (auto calc : calcBlock) {	// parallelisation next iteration
			Gate* gate = calc.getGate();
			int m = gate->getM();
			int n = gate->getN();
			int qubitN = m / 2;

			cudaError_t cudaStatus;			
			// Allocate shared space
			cudaStatus = cudaMalloc((void**)&initialValues, m * sizeof(cuDoubleComplex));
			if (cudaStatus != cudaSuccess) {
				fprintf(stderr, "cudaMalloc failed!");
				goto Error;
			}
			cudaStatus = cudaMalloc((void**)&beforeGate, m * sizeof(cuDoubleComplex));
			if (cudaStatus != cudaSuccess) {
				fprintf(stderr, "cudaMalloc failed!");
				goto Error;
			}
			cudaStatus = cudaMalloc((void**)&afterGate, m * sizeof(cuDoubleComplex));
			if (cudaStatus != cudaSuccess) {
				fprintf(stderr, "cudaMalloc failed!");
				goto Error;
			}
			cudaStatus = cudaMalloc((void**)&gateValues, (m*n) * sizeof(cuDoubleComplex));
			if (cudaStatus != cudaSuccess) {
				fprintf(stderr, "cudaMalloc failed!");
				goto Error;
			}

			std::vector<Qubit*> qubits = calc.getQubits();

			// Generate Host side arrays for qubit values
			if (m == 2) {
				const int arraySize = 2;
				const cuDoubleComplex before[arraySize] = { convertQubitComplex(*(qubits[0]->fetch(0))), convertQubitComplex(*qubits[0]->fetch(1))};
				const cuDoubleComplex gateVal[4] = { convertQubitComplex(gate->fetchValue(0,0)), convertQubitComplex(gate->fetchValue(0,1)), convertQubitComplex(gate->fetchValue(1,0)), convertQubitComplex(gate->fetchValue(1,1)) };
				cuDoubleComplex after[arraySize] = { 0 };

				// Copy input vectors into CUDA memory
				cudaStatus = cudaMemcpy(beforeGate, before, m * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
				if (cudaStatus != cudaSuccess) {
					fprintf(stderr, "cudaMemcpy failed!");
					goto Error;
				}
				cudaStatus = cudaMemcpy(gateValues, gateVal, (m*n) * sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
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
			}
			else if (m == 4) {
				const int arraySize = 4;
				const cuDoubleComplex before[arraySize] = { tensorProduct(qubits, 0), tensorProduct(qubits, 1) , tensorProduct(qubits, 2), tensorProduct(qubits, 3) };
				const cuDoubleComplex gateVal[16] = { 
					convertQubitComplex(gate->fetchValue(0,0)), convertQubitComplex(gate->fetchValue(0,1)), convertQubitComplex(gate->fetchValue(0,2)), convertQubitComplex(gate->fetchValue(0,3)),
					convertQubitComplex(gate->fetchValue(1,0)), convertQubitComplex(gate->fetchValue(1,1)), convertQubitComplex(gate->fetchValue(1,2)), convertQubitComplex(gate->fetchValue(1,3)),
					convertQubitComplex(gate->fetchValue(2,0)), convertQubitComplex(gate->fetchValue(2,1)), convertQubitComplex(gate->fetchValue(2,2)), convertQubitComplex(gate->fetchValue(2,3)),
					convertQubitComplex(gate->fetchValue(3,0)), convertQubitComplex(gate->fetchValue(3,1)), convertQubitComplex(gate->fetchValue(3,2)), convertQubitComplex(gate->fetchValue(3,3)),
				};
				cuDoubleComplex after[arraySize] = { 0 };

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
				ValkGPULib::matrixMul << <1, 4 >> > (afterGate, beforeGate, gateValues, 4);

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
				*qubit->fetch(0) = convertComplexQubit(after[0]) + convertComplexQubit(after[1]);
				*qubit->fetch(1) = convertComplexQubit(after[2]) + convertComplexQubit(after[3]);
				qubit = qubits[1];
				*qubit->fetch(0) = convertComplexQubit(after[0]) + convertComplexQubit(after[2]);
				*qubit->fetch(1) = convertComplexQubit(after[1]) + convertComplexQubit(after[3]);
			}
			cudaFree(initialValues);
			cudaFree(beforeGate);
			cudaFree(afterGate);
			cudaFree(gateValues);
		}
	}
Error:
	cudaFree(initialValues);
	cudaFree(beforeGate);
	cudaFree(afterGate);
	cudaFree(gateValues);
}

std::map<std::string, std::vector<Qubit*>> GPUQuantumProcessor::qubitMapfetchQubitValues()
{
	return circuit_->returnResults();
}

void GPUDevice::loadRegister(Register registerx)
{
	if (registerx.isQuantum()) {
		QuantumRegister qReg = registerx.getQuantumRegister();
		std::string regName = qReg.getIdentifier();
		int width = qReg.getWidth();
		std::vector<Qubit*> registerQubits;
		for (int i = 0; i < width; i++) {
			registerQubits.push_back(qubitFactory->generateQubit());
		}
		registerMap.insert(std::pair<std::string, std::vector<Qubit*>>(regName, registerQubits));
	}
}

void GPUDevice::transferQubitMap()
{
	quantumCircuit->loadQubitMap(registerMap);
}

void GPUDevice::loadConcurrentBlock(ConcurrentBlock block)
{
	quantumCircuit->loadBlock(block);
}

void GPUDevice::runSimulation()
{
	quantumProcessor->loadCircuit(quantumCircuit);
	quantumProcessor->calculate();
}

void GPUDevice::run(std::vector<Register> registers, std::vector<ConcurrentBlock> blocks)
{
	for (auto reg : registers) {
		loadRegister(reg);
	}
	transferQubitMap();
	for (auto block : blocks) {
		loadConcurrentBlock(block);
	}
	runSimulation();
}

std::map<std::string, std::vector<Qubit*>> GPUDevice::revealQuantumState()
{
	return quantumProcessor->qubitMapfetchQubitValues();
}
