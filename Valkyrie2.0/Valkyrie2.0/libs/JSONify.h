#pragma once
#include "BaseTypes.h"


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
