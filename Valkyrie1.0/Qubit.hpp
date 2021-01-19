#pragma once
#include "valkNamespace.hpp"
#include <stdexcept>
#include <vector>

class Qubit {

private:
	bool checkFlag = false;

protected:
	std::vector<valk::ComplexNumber> qubitvals_;

public:
	Qubit() {};
	Qubit(std::vector<valk::ComplexNumber> values) {
		safeLoadValues(values);
	}

	std::vector<valk::ComplexNumber> getQubitValues() {
		return qubitvals_;
	}

	void safeLoadValues(std::vector<valk::ComplexNumber> values);
	
	bool selfCheck() {
		return checkFlag;
	}
};

