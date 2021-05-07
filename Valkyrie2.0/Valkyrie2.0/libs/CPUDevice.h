#pragma once

#include "AbstractDevice.h"

class CPUQubitFactory : public AbstractQubitFactory {
private:
	DeviceType type_;
	std::vector<Qubit*> qubits_;
public:
	CPUQubitFactory(){
		type_ = CPU_;
	}
	Qubit* generateQubit();
	~CPUQubitFactory();
};

class CPUGateFactory : public AbstractGateFactory {
private:
	DeviceType type_;
	std::vector<Gate*> gates_;
public:
	CPUGateFactory() {
		type_ = CPU_;
	}
	Gate* generateGate(GateRequest request);
	~CPUGateFactory();
};

class CPUQuantumCircuit : public AbstractQuantumCircuit {
private:
	DeviceType type_;
	bool done_;
	std::map<std::string, std::vector<Qubit*>> qubitMap_;
	std::vector<std::vector<Calculation>> calculations_;
	CPUGateFactory* gateFactory_;
	int calcCounter = 0;
public:
	CPUQuantumCircuit(CPUGateFactory* gateFactory) {
		gateFactory_ = gateFactory;
		type_ = CPU_;
		done_ = false;
	}
	void loadQubitMap(std::map<std::string, std::vector<Qubit*>> qubitMap);
	void loadBlock(ConcurrentBlock block);
	std::vector<Calculation> getNextCalculation();
	std::map<std::string, std::vector<Qubit*>> returnResults();
	bool checkComplete();
};

class CPUQuantumProcessor : public AbstractQuantumProcessor {
private:
	DeviceType type_;
	AbstractQuantumCircuit* circuit_;
public:
	CPUQuantumProcessor() {
		type_ = CPU_;
	}
	void loadCircuit(AbstractQuantumCircuit* circuit);
	void calculate();
	std::map<std::string, std::vector<Qubit*>> qubitMapfetchQubitValues();
};

class CPUDevice : public AbstractDevice {
private:
	DeviceType type_;
	std::map<std::string, std::vector<Qubit*>> registerMap;
	CPUQubitFactory* qubitFactory;
	CPUGateFactory* gateFactory;
	CPUQuantumCircuit* quantumCircuit;
	CPUQuantumProcessor* quantumProcessor;
public:
	CPUDevice() {
		type_ = CPU_;
		qubitFactory = new CPUQubitFactory();
		gateFactory = new CPUGateFactory();
		quantumCircuit = new CPUQuantumCircuit(gateFactory);
		quantumProcessor = new CPUQuantumProcessor();
	}
	void loadRegister(Register registerx);
	void transferQubitMap();
	void loadConcurrentBlock(ConcurrentBlock block);
	void runSimulation();
	void run(std::vector<Register> registers, std::vector<ConcurrentBlock> blocks);
	std::map<std::string, std::vector<Qubit*>> revealQuantumState();
	void prettyPrintQubitStates(std::map<std::string, std::vector<Qubit*>> qubits) {
		for (std::map<std::string, std::vector<Qubit*>>::iterator it = qubits.begin(); it != qubits.end(); ++it) {
			std::cout << "Register: " << it->first << std::endl;
			std::vector<Qubit*> regQubits = it->second;
			for (int i = 0; i < regQubits.size(); i++) {
				std::cout << "Location [" << i << "]: " << regQubits[i]->fetch(0)->real() << "+" << regQubits[i]->fetch(0)->imag() << "i" << " ||| " << regQubits[i]->fetch(1)->real() << "+" << regQubits[i]->fetch(1)->imag() << "i" << std::endl;
			}
		}
	}
	~CPUDevice() {
		delete qubitFactory;
		delete gateFactory;
		delete quantumCircuit;
		delete quantumProcessor;
	}
};
