#pragma once
#include "BaseTypes.h"
#include <map>
#include <string>
#include <iostream>

/*
	AbstractDevice.h
	Description: Defines interface for quantum processing devices to be implemented either on CPU or GPU.
	The common interface allows us to simplify function calling from higher order files.

	Defined Classes:
	(Abstract) AbstractQubitFactory
	(Abstract) AbstractGateFactory
	(Abstract) AbstractQuantumCircuit
	(Abstract) AbstractQuantumProcessor
	(Abstract) AbstractDevice

*/

// AbstractQubitFactory defines interface for a qubit factory. This class when implemented, will allocate heap memory and
// create instances of the Qubit class (defined in BaseTypes.h) to hold the individual states and names of qubits.
class AbstractQubitFactory {
private: 
	DeviceType type_;
public:
	virtual Qubit* generateQubit() = 0;
};

// AbstractGateFactory defines interfact for a gate factory. This class when implemented, will allocate heap memory and
// create instances of the Gate class (defined in BaseTypes.h) to hold primitive versions of gates.
class AbstractGateFactory {
private:
	DeviceType type_;
public:
	virtual Gate* generateGate(GateRequest request) = 0;
};

// AbstractQuantumCircuit defines the interface for quantum circuits. These are data-structures which will collect the
// calculations requested by the user, and convert them into operable matrix calculations.
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

// AbstractQuantumProcessor defines the interface for the actual calculation part of the quantum simulation
class AbstractQuantumProcessor {
private:
	DeviceType type_;
	AbstractQuantumCircuit* circuit_;
public:
	virtual void loadCircuit(AbstractQuantumCircuit* circuit) = 0;
	virtual void calculate() = 0;
	virtual std::map<std::string, std::vector<Qubit*>> qubitMapfetchQubitValues() = 0;
};

// AbstractDevice provides an interface for the computation device as a whole. This structure will be used to
// collect the classes defined above for a calling function to easily have access to quantum calculation.
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
};


