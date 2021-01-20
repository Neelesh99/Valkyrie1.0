#include "UtilityGates.h"
#include "TensorProduct.h"

valk::GateDimension CNOT::getDimensions() {
	return valk::GateDimension(2, 2);
}


valk::gateType CNOT::getGateType() {
	return valk::CNot;
}

Qubit* CNOT::applyGate(Qubit* inputs[]) {
	Qubit controlQubit = *inputs[0];
	Qubit affectedQubit = *inputs[1];
	
	QubitSpace space = QubitSpace();
	space.tensorProduct(controlQubit, affectedQubit);
	std::vector<valk::ComplexNumber> qubitValues = space.getQubitValues();
	std::vector<valk::ComplexNumber> newValues = { 0,0,0,0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			newValues[i] += qubitValues[j] * gateMatrix[i * 4 + j];
		}
	}

	Qubit* resultQubit = new Qubit(newValues);
	return resultQubit;
}

int  CNOT::averageExecutionTime() {
	return 0;
}