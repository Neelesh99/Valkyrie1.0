#pragma once
#include "CPUDevice.h"
#include <cmath>
#include "GateUtilitiesCPU.h"
#include <chrono>

using namespace std::complex_literals;
const double ROOT2INV = 1.0 / std::pow(2, 0.5);

/*
	CPUDevice.cpp
	Description: This file defines the implementation of the functions defined
	in CPUDevice.h

	Defined Classes:
	CPUQubitFactory
	CPUGateFactory
	CPUQuantumCircuit
	CPUQuantumProcessor
	CPUDevice

*/

// getGateMatrix gneerates basic primitive gates (U, CX)
// uses buildU3GateCPU to construct the parameterised U gate.
std::vector<std::vector<std::complex<double>>> getGateMatrix(GateRequest gate) {
	GateRequestType gateType = gate.getGateType();
	switch (gateType) {
	case I:
		return std::vector<std::vector<std::complex<double>>> { {1, 0}, {0, 1} };
		break;
	case h:
		return std::vector<std::vector<std::complex<double>>> { {ROOT2INV, ROOT2INV}, {ROOT2INV, -1.0 * ROOT2INV} };
		break;
	case cx:
		return std::vector<std::vector<std::complex<double>>> { {1, 0, 0, 0}, { 0, 1, 0, 0 }, { 0, 0, 0, 1 }, { 0, 0, 1, 0 } };
		break;
	case U:
		return buildU3GateCPU(gate);
		break;
	case CX:
		return std::vector<std::vector<std::complex<double>>> { {1, 0, 0, 0}, { 0, 1, 0, 0 }, { 0, 0, 0, 1 }, { 0, 0, 1, 0 } };
		break;
	}
}

// generateQubit allocates heap memory for complex number and loads it into
// a heap memory allocated Qubit and tracks the generated qubits
Qubit* CPUQubitFactory::generateQubit()
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
CPUQubitFactory::~CPUQubitFactory()
{
	for (auto qubit : qubits_) {
		delete qubit->fetch(0);
		delete qubit->fetch(1);
		delete qubit;
	}
}

// generateQubit allocates heap memory for complex numbers and loads it into
// a heap memory allocated Gate and tracks the generated gates
Gate* CPUGateFactory::generateGate(GateRequest request)
{
	std::vector<std::vector<std::complex<double>>> gateMatrix = getGateMatrix(request);
	int gateM = gateMatrix.size();
	int gateN = gateMatrix[0].size();

	Gate* generatedGate = new Gate(gateM, gateN, gateMatrix);
	gates_.push_back(generatedGate);
	return generatedGate;
}

// deconstructor cleans up any heap memory allocation
CPUGateFactory::~CPUGateFactory()
{
	for (auto gate : gates_) {
		delete gate;
	}
}

// zipSVPairs zips together identifiers and locations to generate SVPairs which can be used in
// statevector lookup
std::vector<SVPair> CPUQuantumCircuit::zipSVPairs(std::vector<std::string> names, std::vector<int> locs)
{
	std::vector<SVPair> values;
	for (int i = 0; i < names.size(); i++) {
		values.push_back(SVPair(names[i], locs[i]));
	}
	return values;
}

void CPUQuantumCircuit::loadQubitMap(std::map<std::string, std::vector<Qubit*>> qubitMap)
{
	qubitMap_ = qubitMap;
	sv_ = new StateVector(&qubitMap_);
	sv_->tensorProduct();
}

// loadBlock takes a concurretn block from the Staging module and converts it into
// a series if operable Calculation datatypes
void CPUQuantumCircuit::loadBlock(ConcurrentBlock block)
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
std::vector<Calculation> CPUQuantumCircuit::getNextCalculation()
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
std::map<std::string, std::vector<Qubit*>> CPUQuantumCircuit::returnResults()
{
	return qubitMap_;
}

// For Statevector computation
StateVector* CPUQuantumCircuit::getStateVector()
{
	return sv_;
}

bool CPUQuantumCircuit::checkComplete()
{
	if (calculations_.size() == 0) {
		return true;
	}
	return done_;
}


void CPUQuantumProcessor::loadCircuit(AbstractQuantumCircuit* circuit)
{
	circuit_ = circuit;
}

// calculate method for isolated fast computation
void CPUQuantumProcessor::calculate()
{
	while (!circuit_->checkComplete()) {	// check if there still calculations to complete
		std::vector<Calculation> calcBlock = circuit_->getNextCalculation();	// fetch next calculation
		for (auto calc : calcBlock) {
			Gate* gate = calc.getGate();			
			int m = gate->getM();		// resolve gate dimensions
			int n = gate->getN();
			int qubitN = m / 2;
			std::vector<std::complex<double>> qubitValsBefore_;
			std::vector<std::complex<double>> qubitValsAfter_;
			std::vector<Qubit*> qubits = calc.getQubits();	
			if (m == 2) {
				qubitValsBefore_.push_back(*qubits[0]->fetch(0));
				qubitValsBefore_.push_back(*qubits[0]->fetch(1));
			}
			else {
				// Perform local tensor product
				qubitValsBefore_.push_back(*qubits[0]->fetch(0) * *qubits[1]->fetch(0));
				qubitValsBefore_.push_back(*qubits[0]->fetch(0) * *qubits[1]->fetch(1));
				qubitValsBefore_.push_back(*qubits[0]->fetch(1) * *qubits[1]->fetch(0));
				qubitValsBefore_.push_back(*qubits[0]->fetch(1) * *qubits[1]->fetch(1));
			}
			for (int i = 0; i < m; i++) {
				std::complex<double> val = 0;
				for (int j = 0; j < n; j++) {
					val += gate->fetchValue(i, j) * qubitValsBefore_[j];		// matrix multiplication
				}
				qubitValsAfter_.push_back(val);
			}
			if (m == 2) {
				Qubit* qubit = qubits[0];
				*qubit->fetch(0) = qubitValsAfter_[0];
				*qubit->fetch(1) = qubitValsAfter_[1];
				circuit_->getStateVector()->quickRefresh();						// Since qubit vals are already update, we can just quickly refresh the statevector
			}
			else {
				Qubit* qubit1 = qubits[0];
				Qubit* qubit2 = qubits[1];
				*qubit1->fetch(0) = qubitValsAfter_[0] + qubitValsAfter_[1];
				*qubit1->fetch(1) = qubitValsAfter_[2] + qubitValsAfter_[3];
				*qubit2->fetch(0) = qubitValsAfter_[0] + qubitValsAfter_[2];
				*qubit2->fetch(1) = qubitValsAfter_[1] + qubitValsAfter_[3];
				circuit_->getStateVector()->modifyState(qubitValsAfter_, calc.getLocations()[0], calc.getLocations()[1]);	// For entanglement relations we have to use the modifyState method
			}
		}
	}
}

// calculateWithStateVector for accurate Quantum Computer emulation, uses statevector in it's entirety
void CPUQuantumProcessor::calculateWithStateVector()
{
	long long counter = 0;
	while (!circuit_->checkComplete()) {	// check if there are still calculations to consume
		std::vector<Calculation> calcBlock = circuit_->getNextCalculation();	// fetch calculation		
		for (auto calc : calcBlock) {			
			Gate* gate = calc.getGate();
			int m = gate->getM();
			int n = gate->getN();
			int qubitN = m / 2;
			StateVector* sv = circuit_->getStateVector();						// get current state vector
			std::vector<SVPair> newOrder = calc.getNewOrder(sv->getOrder());	// use the calculation function to work out the new order of the state vector for tail procedure
			
			StateVector* reordered = sv->reorder(newOrder);						// fetch temporary statevector using reordered tensor product
			std::vector<std::vector<std::complex<double>>> gateValues = gate->getArray();
			int svLength = reordered->getState().size();	
			std::vector<std::complex<double>> newValues;			
			for (int i = 0; i < svLength; i++) {						// Only compute what is required
				int startIndex = m * (i / m);
				std::complex<double> acc = 0;
				for (int j = 0; j < m; j++) {
					acc += gateValues[(i % m)][j] * reordered->getSVValue(startIndex + j);
				}
				newValues.push_back(acc);
			}
			
			reordered->directModify(newValues);									// set newValues of reordered state vector
			sv->reconcile(reordered);											// reconcile temporary order for statevector for the original order
		}
	}
}

std::map<std::string, std::vector<Qubit*>> CPUQuantumProcessor::qubitMapfetchQubitValues()
{
	return circuit_->returnResults();
}

void CPUDevice::loadRegister(Register registerx)
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

void CPUDevice::transferQubitMap()
{
	quantumCircuit->loadQubitMap(registerMap);
}

void CPUDevice::loadConcurrentBlock(ConcurrentBlock block)
{
	quantumCircuit->loadBlock(block);
}

void CPUDevice::runSimulation()
{
	quantumProcessor->loadCircuit(quantumCircuit);
	quantumProcessor->calculate();
}

void CPUDevice::runSimulationSV()
{
	quantumProcessor->loadCircuit(quantumCircuit);
	quantumProcessor->calculateWithStateVector();
}

void CPUDevice::run(std::vector<Register> registers, std::vector<ConcurrentBlock> blocks)
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

void CPUDevice::runSV(std::vector<Register> registers, std::vector<ConcurrentBlock> blocks)
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

std::map<std::string, std::vector<Qubit*>> CPUDevice::revealQuantumState()
{
	return quantumProcessor->qubitMapfetchQubitValues();
}
