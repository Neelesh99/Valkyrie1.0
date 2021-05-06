#pragma once

#include "AbstractDevice.h"

class CPUQubitFactory : AbstractQubitFactory {
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

class CPUGateFactory : AbstractGateFactory {
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

class CPUQuantumCircuit : AbstractQuantumCircuit {
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

class CPUQuantumProcessor : AbstractQuantumProcessor {
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
//
//class AbstractDevice {
//private:
//	DeviceType type_;
//public:
//	virtual void loadRegister(Register register) = 0;
//	virtual void loadConcurrentBlock(ConcurrentBlock block) = 0;
//	virtual void runSimulation() = 0;
//	virtual std::vector<Qubit> revealQuantumState() = 0;
//	virtual std::vector<int> measure() = 0;
//};
