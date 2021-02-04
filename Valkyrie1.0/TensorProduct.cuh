#pragma once


#include "Qubit.hpp"
#include "cuda_runtime.h"
#include "valkNamespace.hpp"

EntangledQubits* tensorProductCPU(Qubit a, Qubit b) {
	valk::ComplexNumber* aValues = a.getQubitValues();
	valk::ComplexNumber* bValues = b.getQubitValues();
	valk::ComplexNumber* newValues = new valk::ComplexNumber[4]{ 0, 0, 0, 0 };
	newValues[0] = aValues[0] * bValues[0];
	newValues[1] = aValues[0] * bValues[1];
	newValues[2] = aValues[1] * bValues[0];
	newValues[3] = aValues[1] * bValues[1];
	EntangledQubits* entangledPair = new EntangledQubits(newValues);
	return entangledPair;
}

EntangledQubits* tensorProductGPU(Qubit a, Qubit b) {
	valk::ComplexNumber* aValues = a.getQubitValues();
	valk::ComplexNumber* bValues = b.getQubitValues();
	valk::ComplexNumber* newValues;
	cudaMallocManaged(&newValues, 4 * sizeof(valk::ComplexNumber));
	newValues[0] = aValues[0] * bValues[0];
	newValues[1] = aValues[0] * bValues[1];
	newValues[2] = aValues[1] * bValues[0];
	newValues[3] = aValues[1] * bValues[1];
	EntangledQubits* entangledPair;
	cudaMallocManaged(&entangledPair, sizeof(EntangledQubits));
	entangledPair->safeLoadValues(newValues);
	return entangledPair;
}
