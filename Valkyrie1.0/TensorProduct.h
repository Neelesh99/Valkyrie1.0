#pragma once


#include "Qubit.hpp"
#include "valkNamespace.hpp"


class QubitSpace : public Qubit {

public:

	void tensorProduct(Qubit a, Qubit b) {
		std::vector<valk::ComplexNumber> aValues = a.getQubitValues();
		std::vector<valk::ComplexNumber> bValues = b.getQubitValues();
		std::vector<valk::ComplexNumber> newValues = { 0, 0, 0, 0 };
		newValues[0] = aValues[0] * bValues[0];
		newValues[1] = aValues[0] * bValues[1];
		newValues[2] = aValues[1] * bValues[0];
		newValues[3] = aValues[1] * bValues[1];
		qubitvals_ = newValues;
	}

};	