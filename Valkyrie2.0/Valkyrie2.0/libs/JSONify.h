#pragma once
#include "BaseTypes.h"

/*
	JSONify.h
	Description: File provides interface for JSON printing

*/

// JSONify provides methods to convert results of computation into easily parsable JSON format
class JSONify {
private:
	std::vector<Register> registers_;
	StateVector* sv_;
public:
	JSONify(std::vector<Register> registers, StateVector* sv) {
		registers_ = registers;
		sv_ = sv;
	}
	void printJSON();
};
