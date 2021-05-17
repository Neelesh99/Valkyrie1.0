#include "Measurement.h"
#include <random>
#include <ctime>

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

double StateVectorMeasurement::getMagnitude(std::complex<double> value)
{
	return std::pow(value.real(), 2) + std::pow(value.imag(), 2);
}

double StateVectorMeasurement::getTotalMagnitude()
{
	double total = 0;
	std::vector<std::complex<double>> state = sv_->getState();
	for (int i = 0; i < state.size(); i++) {
		total += getMagnitude(state[i]);
	}
	return total;
}

StateVectorMeasurement::StateVectorMeasurement(StateVector* sv, std::vector<Register> allRegister)
{
	sv_ = sv;
	allRegisters_ = allRegister;
}

void StateVectorMeasurement::measure()
{
	double totalMag =  getTotalMagnitude();
	std::srand(std::time(nullptr));
	int randomVal = std::rand() % 100;
	double measurement = ((double)randomVal / 100) * (totalMag);
	int state = 0;
	if (sv_->getState().size() == 0) {
		return;
	}
	std::vector<std::complex<double>> values = sv_->getState();
	double soFar = getMagnitude(values[state]);
	while (measurement > soFar) {
		state++;
		soFar += getMagnitude(values[state]);
	}
	state_ = state;
}

void StateVectorMeasurement::loadMeasureCommands(std::vector<MeasureCommand> commands)
{
	commands_ = commands;
}

void StateVectorMeasurement::passMeasurementsIntoClassicalRegisters()
{
	for (auto command : commands_) {
		idLocationPairs qReg = command.getFrom();
		idLocationPairs cReg = command.getTo();

		int cRegLoc = findReg(cReg.identifiers[0]);
		if (cRegLoc != -1) {
			ClassicalRegister cRegVal = allRegisters_[cRegLoc].getClassicalRegister();
			cRegVal.setValue(cReg.locations[0], sv_->getVal(state_, SVPair(qReg.identifiers[0], qReg.locations[0])));
			Register cRegFin = allRegisters_[cRegLoc];
			cRegFin.setClassicalRegister(cRegVal);
			allRegisters_[cRegLoc] = cRegFin;
		}
	}
}

void StateVectorMeasurement::printClassicalRegisters()
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

std::vector<Register> StateVectorMeasurement::getAllRegisters()
{
	return allRegisters_;
}

StateVector* StateVectorMeasurement::getStateVector()
{
	return sv_;
}
