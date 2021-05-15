#pragma once
#include "CPUDevice.h"
#include <cmath>
#include "GateUtilitiesCPU.h"

using namespace std::complex_literals;
const double ROOT2INV = 1.0 / std::pow(2, 0.5);



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

CPUQubitFactory::~CPUQubitFactory()
{
	for (auto qubit : qubits_) {
		delete qubit->fetch(0);
		delete qubit->fetch(1);
		delete qubit;
	}
}

Gate* CPUGateFactory::generateGate(GateRequest request)
{
	std::vector<std::vector<std::complex<double>>> gateMatrix = getGateMatrix(request);
	int gateM = gateMatrix.size();
	int gateN = gateMatrix[0].size();

	Gate* generatedGate = new Gate(gateM, gateN, gateMatrix);
	gates_.push_back(generatedGate);
	return generatedGate;
}

CPUGateFactory::~CPUGateFactory()
{
	for (auto gate : gates_) {
		delete gate;
	}
}

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

std::map<std::string, std::vector<Qubit*>> CPUQuantumCircuit::returnResults()
{
	return qubitMap_;
}

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

void CPUQuantumProcessor::calculate()
{
	while (!circuit_->checkComplete()) {
		std::vector<Calculation> calcBlock = circuit_->getNextCalculation();
		for (auto calc : calcBlock) {	// parallelisation next iteration
			Gate* gate = calc.getGate();
			int m = gate->getM();
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
				// Perform tensor product
				qubitValsBefore_.push_back(*qubits[0]->fetch(0) * *qubits[1]->fetch(0));
				qubitValsBefore_.push_back(*qubits[0]->fetch(0) * *qubits[1]->fetch(1));
				qubitValsBefore_.push_back(*qubits[0]->fetch(1) * *qubits[1]->fetch(0));
				qubitValsBefore_.push_back(*qubits[0]->fetch(1) * *qubits[1]->fetch(1));
			}
			for (int i = 0; i < m; i++) {
				std::complex<double> val = 0;
				for (int j = 0; j < n; j++) {
					val += gate->fetchValue(i, j) * qubitValsBefore_[j];
				}
				qubitValsAfter_.push_back(val);
			}
			if (m == 2) {
				Qubit* qubit = qubits[0];
				*qubit->fetch(0) = qubitValsAfter_[0];
				*qubit->fetch(1) = qubitValsAfter_[1];
				circuit_->getStateVector()->quickRefresh();
			}
			else {
				Qubit* qubit1 = qubits[0];
				Qubit* qubit2 = qubits[1];
				*qubit1->fetch(0) = qubitValsAfter_[0] + qubitValsAfter_[1];
				*qubit1->fetch(1) = qubitValsAfter_[2] + qubitValsAfter_[3];
				*qubit2->fetch(0) = qubitValsAfter_[0] + qubitValsAfter_[2];
				*qubit2->fetch(1) = qubitValsAfter_[1] + qubitValsAfter_[3];
				circuit_->getStateVector()->modifyState(qubitValsAfter_, calc.getLocations()[0], calc.getLocations()[1]);
			}
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

std::map<std::string, std::vector<Qubit*>> CPUDevice::revealQuantumState()
{
	return quantumProcessor->qubitMapfetchQubitValues();
}
