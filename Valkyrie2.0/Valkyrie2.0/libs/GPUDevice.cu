#pragma once
#include "GPUDevice.cuh"
#include "cuComplex.h"
#include <cmath>
#include <stdio.h>
#include "GPUCompute.cuh"
#include "GateUtilitiesGPU.cuh"

using namespace std::complex_literals;
const double ROOT2INV = 1.0 / std::pow(2, 0.5);



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
	std::vector<std::vector<std::complex<double>>> gateMatrix = getGateMatrixGPU(request);
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
	for (int i = 0; i < std::pow(2, leftOver); i++) {
		output[4 * i][4 * i] = 1;
		output[4 * i + 1][4 * i + 1] = 1;
		output[4 * i + 2][4 * i + 3] = 1;
		output[4 * i + 3][4 * i + 2] = 1;
	}
	return output;
}

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

void GPUQuantumProcessor::calculateWithStateVector()
{
	// Generate initial arrays
	//cuDoubleComplex* initialValues;
	cuDoubleComplex* beforeGate;
	cuDoubleComplex* gateValues;
	cuDoubleComplex* afterGate;
	while (!circuit_->checkComplete()) {
		std::vector<Calculation> calcBlock = circuit_->getNextCalculation();
		for (auto calc : calcBlock) {			
			Gate* gate = calc.getGate();
			int m = gate->getM();
			int n = gate->getN();
			int qubitN = m / 2;
			StateVector* sv = circuit_->getStateVector();
			int gateDim = sv->getState().size();
			std::vector<SVPair> newOrder = calc.getNewOrder(sv->getOrder());
			StateVector* reordered = sv->reorder(newOrder);
			std::vector<std::vector<std::complex<double>>> gateValuesV;
			if (m == 2) {
				gateValuesV = getGenericUResult(gate, sv->getN());
			}
			if (m == 4) {
				gateValuesV = getCXResult(sv->getN());
			}
			if (gateValuesV.size() == 0) {
				return;
			}
			cudaError_t cudaStatus;
			// Allocate shared space
			cudaStatus = cudaMalloc((void**)&beforeGate, gateDim * sizeof(cuDoubleComplex));
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
				res = ValkGPULib::calculateGPUSV(beforeGate, gateValues, afterGate, reordered, gateValuesV);
			}
			else {
				// Ultra parallel
				res = ValkGPULib::calculateGPULargeSV(beforeGate, gateValues, afterGate, reordered, gateValuesV);
			}
			reordered->directModify(res);
			sv->reconcile(reordered);
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
