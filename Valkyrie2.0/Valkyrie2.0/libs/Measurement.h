#pragma once

#include <map>
#include "BaseTypes.h"

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
};
