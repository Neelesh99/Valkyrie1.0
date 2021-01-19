#pragma once

#include "GenericSingleQubitGate.h"

class HadamardGate : public SingleQubitGate {
public:
	HadamardGate() {
		gateMatrix = new valk::ComplexNumber[4];
		gateMatrix[0] = 1 / std::pow(2, 0.5);
		gateMatrix[1] = 1 / std::pow(2, 0.5);
		gateMatrix[2] = 1 / std::pow(2, 0.5);
		gateMatrix[3] = -1 / std::pow(2, 0.5);
	}
	~HadamardGate() {
		delete gateMatrix;
	}
};

class IdentityGate : public SingleQubitGate {
public:
	IdentityGate() {
		gateMatrix = new valk::ComplexNumber[4];
		gateMatrix[0] = 1;
		gateMatrix[1] = 0;
		gateMatrix[2] = 0;
		gateMatrix[3] = 1;
	}
	~IdentityGate() {
		delete gateMatrix;
	}
};


class CNOT : public Gate {
protected:
	valk::ComplexNumber* gateMatrix;
	int target = 0;
public:
	CNOT(int targetLine) {
		gateMatrix = new valk::ComplexNumber[16];
		//row 1
		gateMatrix[0] = 1;
		gateMatrix[1] = 0;
		gateMatrix[2] = 0;
		gateMatrix[3] = 0;
		//row 2
		gateMatrix[4] = 0;
		gateMatrix[5] = 1;
		gateMatrix[6] = 0;
		gateMatrix[7] = 0;
		//row 3
		gateMatrix[8] = 0;
		gateMatrix[9] = 0;
		gateMatrix[10] = 0;
		gateMatrix[11] = 1;
		//row 4
		gateMatrix[12] = 0;
		gateMatrix[13] = 0;
		gateMatrix[14] = 1;
		gateMatrix[15] = 0;
		target = targetLine;
	}
	valk::GateDimension getDimensions();
	bool checkInputs(Qubit singleQubitGate);
	valk::gateType getGateType();
	Qubit* applyGate(Qubit** inputs);
	int averageExecutionTime();
	int getGateTarget() {
		return target;
	}
	valk::ComplexNumber* exposeMatrix() {
		return gateMatrix;
	}
};