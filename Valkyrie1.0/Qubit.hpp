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

	valk::ComplexNumber& operator[](int index) {
		if (index >= 0 && index < 2) {
			return qubitvals_[index];
		}
		throw std::out_of_range("Index out of range");
	}

	void safeLoadValues(valk::ComplexNumber* values);
};

class EntangledQubits : public Qubit {

public:
	EntangledQubits() {};
	EntangledQubits(valk::ComplexNumber* values) {
		safeLoadValues(values);
	}
	valk::ComplexNumber& operator[](int index) {
		if (index >= 0 && index < 4) {
			return qubitvals_[index];
		}
	}
};

