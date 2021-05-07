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
			ValkGPULib::calculateGPU(beforeGate, gateValues, afterGate, calc.getGate(), calc.getQubits());
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
