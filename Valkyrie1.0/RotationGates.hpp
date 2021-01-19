#pragma once
#include "Gate.hpp"
#include "valkNamespace.hpp"
#include "GenericSingleQubitGate.h"
#include <cmath>

using namespace std::complex_literals;

class RotationX : public SingleQubitGate {
public:
	RotationX(double angle) {
		gateMatrix = new valk::ComplexNumber[4];
		gateMatrix[0] = std::cos(angle/2);
		gateMatrix[1] = -1i * std::sin(angle/2);
		gateMatrix[2] = -1i * std::sin(angle/2);
		gateMatrix[3] = std::cos(angle/2);
	}
	~RotationX() {
		delete gateMatrix;
	}
};

class RotationY : public SingleQubitGate {
public:
	RotationY(double angle) {
		gateMatrix = new valk::ComplexNumber[4];
		gateMatrix[0] = std::cos(angle / 2);
		gateMatrix[1] = -1*std::sin(angle / 2);
		gateMatrix[2] = std::sin(angle / 2);
		gateMatrix[3] = std::cos(angle / 2);
	}
	~RotationY() {
		delete gateMatrix;
	}
};

class RotationZ : public SingleQubitGate {
public:
	RotationZ(double angle) {
		gateMatrix = new valk::ComplexNumber[4];
		double halved = -1*angle/2;
		gateMatrix[0] = std::exp(halved * 1i);
		gateMatrix[1] = 0;
		gateMatrix[2] = 0;
		gateMatrix[3] = std::exp(halved * 1i);
	}
	~RotationZ() {
		delete gateMatrix;
	}
};