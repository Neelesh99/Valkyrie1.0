#pragma once
#include "valkNamespace.hpp"
#include <stdexcept>

class Qubit {

private:
	bool checkFlag = false;

protected:
	valk::ComplexNumber* qubitvals_;
	valk::ComplexNumber* secondVal_;

public:
	Qubit() {};
	Qubit(valk::ComplexNumber* values) {
		safeLoadValues(values);
	}

	valk::ComplexNumber* getQubitValues() {
		return qubitvals_;
	}

	void safeLoadValues(valk::ComplexNumber* values);
	
	bool selfCheck() {
		return checkFlag;
	}
};

