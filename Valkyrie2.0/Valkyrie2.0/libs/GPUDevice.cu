#pragma once
#include "GPUDevice.cuh"
#include "cuComplex.h"
#include <cmath>
#include <stdio.h>
#include "GPUCompute.cuh"
#include "GateUtilitiesGPU.cuh"

using namespace std::complex_literals;
const double ROOT2INV = 1.0 / std::pow(2, 0.5);

/*
	GPUDevice.cu
	Description: This file defines the implementation of the functions defined
	in GPUDevice.cuh

	Defined Classes:
	GPUQubitFactory
	GPUGateFactory
	GPUQuantumCircuit
	GPUQuantumProcessor
	GPUDevice

*/

// getGateMatrix gneerates basic primitive gates (U, CX)
// uses buildU3GateGPU to construct the parameterised U gate.
std::vector<std::vector<std::complex<double>>> getGateMatrixGPU(GateRequest gate) {
	GateRequestType gateType = gate.getGateType();
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
	case U:
		return buildU3GateGPU(gate);
		break;
	case CX:
		return std::vector<std::vector<std::complex<double>>> { {1, 0, 0, 0}, { 0, 1, 0, 0 }, { 0, 0, 0, 1 }, { 0, 0, 1, 0 } };
		break;
	}
}

// generateQubit allocates heap memory for complex number and loads it into
// a heap memory allocated Qubit and tracks the generated qubits
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

// deconstructor cleans up any heap memory allocation
GPUQubitFactory::~GPUQubitFactory()
{
	for (auto qubit : qubits_) {
		delete qubit->fetch(0);
		delete qubit->fetch(1);
		delete qubit;
	}
}

// generateQubit allocates heap memory for complex numbers and loads it into
// a heap memory allocated Gate and tracks the generated gates
Gate* GPUGateFactory::generateGate(GateRequest request)
{
	std::vector<std::vector<std::complex<double>>> gateMatrix = getGateMatrixGPU(request);
	int gateM = gateMatrix.size();
	int gateN = gateMatrix[0].size();

	Gate* generatedGate = new Gate(gateM, gateN, gateMatrix);
	gates_.push_back(generatedGate);
	return generatedGate;
}

// deconstructor cleans up any heap memory allocation
GPUGateFactory::~GPUGateFactory()
{
	for (auto gate : gates_) {
		delete gate;
	}
}

// zipSVPairs zips together identifiers and locations to generate SVPairs which can be used in
// statevector lookup
std::vector<SVPair> GPUQuantumCircuit::zipSVPairs(std::vector<std::string> names, std::vector<int> locs)
{
	std::vector<SVPair> values;
	for (int i = 0; i < names.size(); i++) {
		values.push_back(SVPair(names[i], locs[i]));
	}
	return values;
}

void GPUQuantumCircuit::loadQubitMap(std::map<std::string, std::vector<Qubit*>> qubitMap)
{
	qubitMap_ = qubitMap;
	sv_ = new StateVector(&qubitMap_);
	sv_->tensorProduct();
}

// loadBlock takes a concurrent block from the Staging module and converts it into
// a series if operable Calculation datatypes
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
		std::vector<SVPair> svPairs = zipSVPairs(registers, locations);
		Calculation calc = Calculation(gateTrue, qubitValues, svPairs);
		calcs.push_back(calc);
	}
	calculations_.push_back(calcs);
}

// getNextCalculation is used during the processing, to queue up calculations and 
// raises the done_ flag if computation is complete
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

// For fast computation
std::map<std::string, std::vector<Qubit*>> GPUQuantumCircuit::returnResults()
{
	return qubitMap_;
}

// For Statevector computation
StateVector* GPUQuantumCircuit::getStateVector()
{
	return sv_;
}

bool GPUQuantumCircuit::checkComplete()
{
	if (calculations_.size() == 0) {
		return true;
	}
	return done_;
}

// getCXResults generates an 2^n by 2^n matrix from the tensor product of I gates and a final CX gate
// returns this matrix for computation
std::vector<std::vector<std::complex<double>>> GPUQuantumProcessor::getCXResult(int n)
{
	// n is the number of qubits, we have to have n-2 I gates and then a CX gate at the end
	if (n < 2) {
		return std::vector<std::vector<std::complex<double>>>();
	}
	std::vector<std::vector<std::complex<double>>> output;
	// overall sidelength of resultant gate
	int dimOverall = std::pow(2, n);
	// number of I multiplications required
	int leftOver = n - 2;
	if (leftOver == 0) {
		output = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0} };
		return output;
	}
	output.resize(dimOverall);
	for (int i = 0; i < dimOverall; i++) {
		std::vector<std::complex<double>> subVec;
		subVec.resize(dimOverall);
		output[i] = subVec;
	}
	// skinny calculation due to the CX being the last matrix in a series of I tensor products
	// using tail methodology
	for (int i = 0; i < std::pow(2, leftOver); i++) {
		output[4 * i][4 * i] = 1;
		output[4 * i + 1][4 * i + 1] = 1;
		output[4 * i + 2][4 * i + 3] = 1;
		output[4 * i + 3][4 * i + 2] = 1;
	}
	return output;
}

// getGenericUResult return tensor product of a series of I gates and finally the U gate we are applying
std::vector<std::vector<std::complex<double>>> GPUQuantumProcessor::getGenericUResult(Gate* gate, int n)
{
	// n is the number of qubits, we have to have n-2 I gates and then a CX gate at the end
	if (n < 1) {
		return std::vector<std::vector<std::complex<double>>>();
	}
	std::vector<std::vector<std::complex<double>>> output;
	// overall sidelength of resultant gate
	int dimOverall = std::pow(2, n);
	// number of I multiplications required
	int leftOver = n - 1;
	if (leftOver == 0) {
		output = gate->getArray();
		return output;
	}
	output.resize(dimOverall);
	for (int i = 0; i < dimOverall; i++) {
		std::vector<std::complex<double>> subVec;
		subVec.resize(dimOverall);
		output[i] = subVec;
	}
	// skinny calculation due to the CX being the last matrix in a series of I tensor products
	// using tail methodology
	for (int i = 0; i < std::pow(2, leftOver); i++) {
		output[2 * i][2 * i] = gate->fetchValue(0, 0);
		output[2 * i][2 * i + 1] = gate->fetchValue(0, 1);
		output[2 * i + 1][2 * i] = gate->fetchValue(1, 0);
		output[2 * i + 1][2 * i + 1] = gate->fetchValue(1, 1);
	}
	return output;
}

void GPUQuantumProcessor::loadCircuit(AbstractQuantumCircuit* circuit)
{
	circuit_ = circuit;
}

// calculate method for isolated fast computation
void GPUQuantumProcessor::calculate()
{
	// Generate initial arrays
	//cuDoubleComplex* initialValues;
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
			cudaStatus = cudaMalloc((void**)&beforeGate, m * sizeof(cuDoubleComplex));				// Allocate GPU memory for gate arrays
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
			// Uses GPUCompute.cuh functions to perform calculation
			std::vector<std::complex<double>> res = ValkGPULib::calculateGPU(beforeGate, gateValues, afterGate, calc.getGate(), calc.getQubits());
			if (res.size() == 2) {
				circuit_->getStateVector()->quickRefresh();
			}
			if (res.size() == 4) {
				circuit_->getStateVector()->modifyState(res, calc.getLocations()[0], calc.getLocations()[1]);
			}
			cudaFree(beforeGate);
			cudaFree(afterGate);
			cudaFree(gateValues);
		}
	}
	return;
Error:
	cudaFree(beforeGate);
	cudaFree(afterGate);
	cudaFree(gateValues);
}

// calculateWithStateVector for accurate Quantum Computer emulation, uses statevector in it's entirety
void GPUQuantumProcessor::calculateWithStateVector()
{
	// Generate initial arrays
	//cuDoubleComplex* initialValues;
	cuDoubleComplex* beforeGate;
	cuDoubleComplex* gateValues;
	cuDoubleComplex* afterGate;
	while (!circuit_->checkComplete()) {	// check if there are still calculations to consume
		std::vector<Calculation> calcBlock = circuit_->getNextCalculation();	// fetch calculation
		for (auto calc : calcBlock) {			
			Gate* gate = calc.getGate();
			int m = gate->getM();
			int n = gate->getN();
			int qubitN = m / 2;
			StateVector* sv = circuit_->getStateVector();						// get current state vector
			int gateDim = sv->getState().size();
			std::vector<SVPair> newOrder = calc.getNewOrder(sv->getOrder());	// use the calculation function to work out the new order of the state vector for tail procedure
			StateVector* reordered = sv->reorder(newOrder);						// fetch temporary statevector using reordered tensor product
			std::vector<std::vector<std::complex<double>>> gateValuesV;
			if (m == 2) {
				gateValuesV = getGenericUResult(gate, sv->getN());				// Generate full gate matrix
			}
			if (m == 4) {
				gateValuesV = getCXResult(sv->getN());							// Generate full gate matrix
			}
			if (gateValuesV.size() == 0) {
				return;
			}
			cudaError_t cudaStatus;
			// Allocate shared space
			cudaStatus = cudaMalloc((void**)&beforeGate, gateDim * sizeof(cuDoubleComplex));		// Allocate GPU memory for gate arrays
			if (cudaStatus != cudaSuccess) {
				fprintf(stderr, "cudaMalloc failed!");
				goto Error;
			}
			cudaStatus = cudaMalloc((void**)&afterGate, gateDim * sizeof(cuDoubleComplex));
			if (cudaStatus != cudaSuccess) {
				fprintf(stderr, "cudaMalloc failed!");
				goto Error;
			}
			cudaStatus = cudaMalloc((void**)&gateValues, (gateDim * gateDim) * sizeof(cuDoubleComplex));
			if (cudaStatus != cudaSuccess) {
				fprintf(stderr, "cudaMalloc failed!");
				goto Error;
			}
			std::vector<std::complex<double>> res;
			if (gateDim < 256) {	
				res = ValkGPULib::calculateGPUSV(beforeGate, gateValues, afterGate, reordered, gateValuesV);		// For smaller scale gates we used partially parallel processing
			}
			else {
				// Ultra parallel
				res = ValkGPULib::calculateGPULargeSV(beforeGate, gateValues, afterGate, reordered, gateValuesV);	// Larger gate require fully parallel processing
			}
			reordered->directModify(res);								// set newValues of reordered state vector
			sv->reconcile(reordered);									// reconcile temporary order for statevector for the original order
			cudaFree(beforeGate);
			cudaFree(afterGate);
			cudaFree(gateValues);
		}
	}
	return;
Error:
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

void GPUDevice::runSimulationSV()
{
	quantumProcessor->loadCircuit(quantumCircuit);
	quantumProcessor->calculateWithStateVector();
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

void GPUDevice::runSV(std::vector<Register> registers, std::vector<ConcurrentBlock> blocks)
{
	for (auto reg : registers) {
		loadRegister(reg);
	}
	transferQubitMap();
	for (auto block : blocks) {
		loadConcurrentBlock(block);
	}
	runSimulationSV();
}

std::map<std::string, std::vector<Qubit*>> GPUDevice::revealQuantumState()
{
	return quantumProcessor->qubitMapfetchQubitValues();
}
