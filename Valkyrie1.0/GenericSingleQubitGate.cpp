#include "GenericSingleQubitGate.h"

valk::GateDimension SingleQubitGate::getDimensions() {
	return valk::GateDimension(2, 2);
}

bool SingleQubitGate::checkInputs(Qubit entry) {
	return entry.selfCheck();
}

valk::gateType SingleQubitGate::getGateType() {
	return valk::SingleQubit;
}

Qubit* SingleQubitGate::applyGate(Qubit* inputs) {
	Qubit applicableQubit = inputs[0];
	valk::ComplexNumber oldVal1 = applicableQubit.getQubitValues()[0];
	valk::ComplexNumber oldVal2 = applicableQubit.getQubitValues()[1];
	valk::ComplexNumber newVal1 = oldVal1 * gateMatrix[0];
	newVal1 += oldVal2 * gateMatrix[1];
	valk::ComplexNumber newVal2 = oldVal1 * gateMatrix[2];
	newVal2 += oldVal2 * gateMatrix[3];
	valk::ComplexNumber newValues[2] = { newVal1, newVal2 };

	Qubit* resultQubit = new Qubit(newValues);
	return resultQubit;
}

int SingleQubitGate::averageExecutionTime() {
	return 0;
}