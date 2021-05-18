#include "JSONify.h"

void JSONify::printJSON()
{
	std::string starter = "{";
	// Tell it about the state vector
	starter = starter + "\"StateVector\" : [ \n";
	for (int i = 0; i < sv_->getState().size(); i++) {
		std::complex<double> svVal = sv_->getState()[i];
		starter = starter + "\"" + std::to_string(svVal.real()) + " + " + std::to_string(svVal.imag()) + "i\",\n";
	}
	starter = starter.substr(0, starter.size() - 2);
	starter = starter + "\n],\n";
	starter = starter + "\"ClassicalRegisters\" : [";
	for (int i = 0; i < registers_.size(); i++) {
		if (!registers_[i].isQuantum()) {
			ClassicalRegister cr = registers_[i].getClassicalRegister();
			starter = starter + "{ \n \"id\": \"" + cr.getIdentifier() + "\", \n \"values\": [ \n";
			for (int j = 0; j < cr.getWidth(); j++) {
				starter = starter + std::to_string(cr.getValue(j)) + ",\n";
			}
			starter = starter.substr(0, starter.size() - 2);
			starter = starter + "\n] \n},";
		}
	}
	starter = starter.substr(0, starter.size() - 1);
	starter = starter + "\n]";
	starter = starter + "\n}";
	std::cout << starter << std::endl;
}
