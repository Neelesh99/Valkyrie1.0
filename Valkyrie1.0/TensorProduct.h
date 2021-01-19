#pragma once


#include "Qubit.hpp"
#include "valkNamespace.hpp"


class QubitSpace : public Qubit {

public:

	void tensorProduct(Qubit a, Qubit b) {
		valk::ComplexNumber* aValues = a.getQubitValues();
		valk::ComplexNumber* bValues = b.getQubitValues();
		valk::ComplexNumber* newValues = new valk::ComplexNumber[4];
		newValues[0] = aValues[0] * bValues[0];
		newValues[1] = aValues[0] * bValues[1];
		newValues[2] = aValues[1] * bValues[0];
		newValues[3] = aValues[1] * bValues[1];
		qubitvals_ = newValues;
	}

	~QubitSpace() {
		delete qubitvals_;
	}
};	