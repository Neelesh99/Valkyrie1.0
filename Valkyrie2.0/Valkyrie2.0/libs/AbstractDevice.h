#pragma once
#include "BaseTypes.h"
#include <map>
#include <string>
#include <iostream>

class AbstractQubitFactory {
private: 
	DeviceType type_;
public:
	virtual Qubit* generateQubit() = 0;
};

class AbstractGateFactory {
private:
	DeviceType type_;
public:
	virtual Gate* generateGate(GateRequest request) = 0;
};

class AbstractQuantumCircuit {
private:
	DeviceType type_;
	bool done_;
public:
	virtual void loadQubitMap(std::map<std::string, std::vector<Qubit*>> qubitMap) = 0;
	virtual void loadBlock(ConcurrentBlock block) = 0;
	virtual std::vector<Calculation> getNextCalculation() = 0;
	virtual std::map<std::string, std::vector<Qubit*>> returnResults() = 0;
	virtual StateVector* getStateVector() = 0;
	virtual bool checkComplete() = 0;
};

class AbstractQuantumProcessor {
private:
	DeviceType type_;
	AbstractQuantumCircuit* circuit_;
public:
	virtual void loadCircuit(AbstractQuantumCircuit* circuit) = 0;
	virtual void calculate() = 0;
	virtual std::map<std::string, std::vector<Qubit*>> qubitMapfetchQubitValues() = 0;
};

class AbstractDevice {
private:
	DeviceType type_;
public:
	virtual void loadRegister(Register registerx) = 0;
	virtual void transferQubitMap() = 0;
	virtual void loadConcurrentBlock(ConcurrentBlock block) = 0;
	virtual void runSimulation() = 0;
	virtual void run(std::vector<Register> registers, std::vector<ConcurrentBlock> blocks) = 0;
	virtual std::map<std::string, std::vector<Qubit*>> revealQuantumState() = 0;
	// virtual std::vector<int> measure() = 0; next iteration
};


