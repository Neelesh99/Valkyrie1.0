#pragma once
#include "Gate.hpp"
#include "GenericSingleQubitGate.h"

using namespace std::complex_literals;

class PauliX : public SingleQubitGate {
public:
	PauliX() {
		gateMatrix = new valk::ComplexNumber[4];
		gateMatrix[0] = 0;
		gateMatrix[1] = 1;
		gateMatrix[2] = 1;
		gateMatrix[3] = 0;
	}
	~PauliX() {
		delete gateMatrix;
	}
};

class PauliY : public SingleQubitGate {
public:
	PauliY() {
		gateMatrix = new valk::ComplexNumber[4];
		gateMatrix[0] = 0;
		gateMatrix[1] = -1i;
		gateMatrix[2] = 1i;
		gateMatrix[3] = 0;
	}
	~PauliY() {
		delete gateMatrix;
	}
};
class PauliZ : public SingleQubitGate {
public:
	PauliZ() {
		gateMatrix = new valk::ComplexNumber[4];
		gateMatrix[0] = 1;
		gateMatrix[1] = 0;
		gateMatrix[2] = 0;
		gateMatrix[3] = -1;
	}
	~PauliZ() {
		delete gateMatrix;
	}
};