#include "Measurement.h"
#include <random>

bool MeasurementCalculator::selectState0(Qubit* val)
{
	std::complex<double>* s_0 = val->fetch(0);
	std::complex<double>* s_1 = val->fetch(1);

	double val_0 = std::pow(s_0->real(), 2) + std::pow(s_0->imag(), 2);
	double val_1 = std::pow(s_1->real(), 2) + std::pow(s_1->imag(), 2);

	double randomVal = ((double)std::rand() / (RAND_MAX)) * (val_0 + val_1);
	return randomVal <= val_0;
}

MeasurementCalculator::MeasurementCalculator(std::vector<Register> allRegister)
{
	allRegisters_ = allRegister;
}

void MeasurementCalculator::registerHandover(std::map<std::string, std::vector<Qubit*>> registerMap)
{
	registerMap_ = registerMap;
}

int MeasurementCalculator::measureSingle(std::string registerName, int location)
{
	Qubit* quantumValue = registerMap_[registerName][location];
	return selectState0(quantumValue) ? 0 : 1;
}

void MeasurementCalculator::measureAll(){
	for (std::map<std::string, std::vector<Qubit*>>::iterator it = registerMap_.begin(); it != registerMap_.end(); ++it) {
		for (int i = 0; i < it->second.size(); i++) {
			measuredMap_[it->first].push_back(measureSingle(it->first, i));
		}
	}
}

std::map<std::string, std::vector<int>> MeasurementCalculator::returnMeasurementMap()
{
	return measuredMap_;
}

void MeasurementCalculator::loadMeasureCommands(std::vector<MeasureCommand> commands)
{
	commands_ = commands;
}

void MeasurementCalculator::passMeasurementsIntoClassicalRegisters()
{
	for (auto command : commands_) {
		idLocationPairs qReg = command.getFrom();
		idLocationPairs cReg = command.getTo();

		int cRegLoc = findReg(cReg.identifiers[0]);
		if (cRegLoc != -1) {
			ClassicalRegister cRegVal = allRegisters_[cRegLoc].getClassicalRegister();
			cRegVal.setValue(cReg.locations[0], measuredMap_[qReg.identifiers[0]][qReg.locations[0]]);
			Register cRegFin = allRegisters_[cRegLoc];
			cRegFin.setClassicalRegister(cRegVal);
			allRegisters_[cRegLoc] = cRegFin;
		}
	}
}

Register MeasurementCalculator::fetchRegister(std::string name)
{
	int loc = findReg(name);
	if (loc == -1) {
		loc = 0;
	}
	return allRegisters_[loc];
}

void MeasurementCalculator::printClassicalRegisters()
{
	for (auto reg : allRegisters_) {
		if (!reg.isQuantum()) {
			ClassicalRegister cReg = reg.getClassicalRegister();
			std::cout << "Classical Register Identifier: " << cReg.getIdentifier() << std::endl;
			for (int i = 0; i < cReg.getWidth(); i++) {
				std::cout << "Location [" << i << "]: " << cReg.getValue(i) << std::endl;
			}
		}
	}
}
