#pragma once
#include "Gate.hpp"


using namespace std::complex_literals;

class SingleQubitGate: public Gate {
protected:
	valk::ComplexNumber* gateMatrix;
public:
	SingleQubitGate() {
		//gateMatrix = new valk::ComplexNumber[4];
		//gateMatrix[0] = 0;
		//gateMatrix[1] = 1;
		//gateMatrix[2] = 1;
		//gateMatrix[3] = 0;
	}
	valk::GateDimension getDimensions();
	bool checkInputs(Qubit singleQubitGate);
	valk::gateType getGateType();
	Qubit* applyGate(Qubit* inputs[]);
	int averageExecutionTime();
	valk::ComplexNumber* exposeMatrix() {
		return gateMatrix;
	}
};