#include "CPUDevice.h"
#include <cmath>

using namespace std::complex_literals;
const double ROOT2INV = 1.0 / std::pow(2, 0.5);

std::vector<std::vector<std::complex<double>>> getGateMatrix(GateRequestType gateType) {
	switch (gateType) {
	case h:
		return std::vector<std::vector<std::complex<double>>> { {ROOT2INV, ROOT2INV}, {ROOT2INV, -1.0 * ROOT2INV} };
		break;
	case cx:
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
		delete qubit;
	}
}

Gate* CPUGateFactory::generateGate(GateRequest request)
{
	std::vector<std::vector<std::complex<double>>> gateMatrix = getGateMatrix(request.getGateType());
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

void CPUQuantumCircuit::loadQubitMap(std::map<std::string, std::vector<Qubit*>> qubitMap)
{
	qubitMap_ = qubitMap;
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
		Calculation calc = Calculation(gateTrue, qubitValues);
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
			std::vector<Qubit*> qubits = calc.getQubits();
			for (int i = 0; i < qubitN; i++) {
				Qubit* qubit = qubits[i];
				std::complex<double> val = 0;
				for (int j = 0; j < n; j++) {
					val += gate->fetchValue(2 * i, j) * *qubits[j / 2]->fetch(j % 2);
				}
				*qubit->fetch(0) = val;
				for (int j = 0; j < n; j++) {
					val += gate->fetchValue(2 * i + 1, j) * *qubits[j / 2]->fetch(j % 2);
				}
				*qubit->fetch(1) = val;
			}
		}
	}
}

std::map<std::string, std::vector<Qubit*>> CPUQuantumProcessor::qubitMapfetchQubitValues()
{
	return circuit_->returnResults();
}
