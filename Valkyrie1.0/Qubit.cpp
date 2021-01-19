#include "Qubit.hpp"



void Qubit::safeLoadValues(std::vector<valk::ComplexNumber> values) {

	if (values.size() > 1) {
		qubitvals_ = values;
	}
}