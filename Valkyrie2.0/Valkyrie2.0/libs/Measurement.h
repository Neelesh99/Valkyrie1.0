#pragma once

#include <map>
#include "BaseTypes.h"
#include <iostream>

/*
	Measurement.h
	Description: File provides interface for Quantum state measurement

*/

// MeasurementCalculator provides methods for measurement of the quantum state
// into classical registers for fast compute mode
class MeasurementCalculator {
private:
	std::map<std::string, std::vector<Qubit*>> registerMap_;
	std::map<std::string, std::vector<int>> measuredMap_;
	bool selectState0(Qubit* val);
	std::vector<MeasureCommand> commands_;
	std::vector<Register> allRegisters_;
	int findReg(std::string identifier) {
		for (int i = 0; i < allRegisters_.size(); i++) {
			if (allRegisters_[i].getName() == identifier) {
				return i;
			}
		}
		return -1;
	}
public:
	MeasurementCalculator(std::vector<Register> allRegisters);
	void registerHandover(std::map<std::string, std::vector<Qubit*>> registerMap);
	int measureSingle(std::string registerName, int location);
	void measureAll();
	std::map<std::string, std::vector<int>> returnMeasurementMap();
	void loadMeasureCommands(std::vector<MeasureCommand> commands);
	void passMeasurementsIntoClassicalRegisters();
	Register fetchRegister(std::string name);
	std::vector<Register> getAllRegisters() {
		return allRegisters_;
	}
	void printClassicalRegisters();
};

// StateVectorMeasurement provides methods for measurement of the entire
// statevector in statevector compute mode
class StateVectorMeasurement {
private:
	StateVector* sv_;
	double getMagnitude(std::complex<double> value);
	double getTotalMagnitude();
	int state_;
	std::vector<MeasureCommand> commands_;
	std::vector<Register> allRegisters_;
	int findReg(std::string identifier) {
		for (int i = 0; i < allRegisters_.size(); i++) {
			if (allRegisters_[i].getName() == identifier) {
				return i;
			}
		}
		return -1;
	}
public:
	StateVectorMeasurement(StateVector* sv, std::vector<Register> allRegister);
	void measure();
	void loadMeasureCommands(std::vector<MeasureCommand> commands);
	void passMeasurementsIntoClassicalRegisters();
	void printClassicalRegisters();
	std::vector<Register> getAllRegisters();
	StateVector* getStateVector();
};
