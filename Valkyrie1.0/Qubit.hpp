#pragma once
#include "valkNamespace.hpp"
#include <stdexcept>
#include <vector>

class Qubit {

protected:
	int* qubitDimensions;
	valk::ComplexNumber* qubitvals_;

public:
	Qubit() {};
	Qubit(valk::ComplexNumber* values) {
		safeLoadValues(values);
	}

	valk::ComplexNumber* getQubitValues() {
		return qubitvals_;
	}

	int* getQubitDimensions() {
		return qubitDimensions;
	}

	void setQubitDimensions(int* dimensions) {
		qubitDimensions = dimensions;
	}

	void safeLoadValues(valk::ComplexNumber* values);
};

class EntangledQubits : public Qubit {

public:
	EntangledQubits() {};
	EntangledQubits(valk::ComplexNumber* values) {
		safeLoadValues(values);
	}
};

