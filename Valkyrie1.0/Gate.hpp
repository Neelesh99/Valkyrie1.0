#pragma once
#include <vector>
#include "valkNamespace.hpp"
#include "QReg.hpp"
#include "Qubit.hpp"


class Gate {

public:
	virtual valk::GateDimension getDimensions() = 0;
	bool checkInputs(QReg singleRegGate);
	bool checkInputs(Qubit singleQubitGate);
	bool checkInputs(std::vector<QReg> multiRegGate);
	virtual valk::gateType getGateType() = 0;
	virtual Qubit* applyGate(Qubit* inputs) = 0;
	virtual int averageExecutionTime() = 0;
	valk::ComplexNumber* exposeMatrix();
};