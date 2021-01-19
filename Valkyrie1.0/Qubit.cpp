#include "Qubit.hpp"



void Qubit::safeLoadValues(valk::ComplexNumber* values) {
	valk::ComplexNumber* firstVal = values;
	valk::ComplexNumber* secondVal = dynamic_cast<valk::ComplexNumber*>(values + 1);

	if (secondVal) {
		qubitvals_ = values;
		secondVal_ = qubitvals_ + 1;
		checkFlag = true;
		return;
	}
	throw std::invalid_argument("Qubit load failed because 2 entries were not given");
}