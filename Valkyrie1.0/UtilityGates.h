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