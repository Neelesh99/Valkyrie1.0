#pragma once

#include "AbstractDevice.h"

class CPUQubitFactory : AbstractQubitFactory {
private:
	DeviceType type_;
	std::vector<Qubit*> qubits_;
public:
	Qubit* generateQubit();
	~CPUQubitFactory();
};

class CPUGateFactory : AbstractGateFactory {
private:
	DeviceType type_;
	std::vector<Gate*> gates_;
public:
	Gate* generateGate(GateRequest request);
};

//class AbstractQuantumCircuit {
//private:
//	DeviceType type_;
//	bool done_;
//public:
//	virtual void loadQubitMap(std::map<std::string, std::vector<Qubit*>> qubitMap) = 0;
//	virtual void loadBlock(ConcurrentBlock block) = 0;
//	virtual Calculation getNextCalculation() = 0;
//	virtual void returnResults(std::complex<double>* quabitVals) = 0;
//	virtual bool checkComplete() = 0;
//};
//
//class AbstractQuantumProcessor {
//private:
//	DeviceType type_;
//	AbstractQuantumCircuit* circuit_;
//public:
//	virtual void loadCircuit(AbstractQuantumCircuit* circuit) = 0;
//	virtual void calculate() = 0;
//	virtual std::map<std::string, std::vector<Qubit*>> qubitMapfetchQubitValues() = 0;
//};
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
