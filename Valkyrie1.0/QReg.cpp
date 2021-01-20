#include "QReg.hpp"


void QReg::push_(Qubit newEntry) {
	int newLength = registerLength + 1;
	Qubit* newArray = new Qubit[newLength];
	for (int i = 0; i < registerLength; i++) {
		newArray[i] = qubits[i];
	}
	newArray[registerLength] = newEntry;
	qubits = newArray;
	registerLength = newLength;
}

QReg QReg::addRegisters_(QReg first, QReg second) {
	int newRegisterLength = first.getLength() + second.getLength();
	Qubit* newArray = new Qubit[newRegisterLength];
	
	auto firstQubits = first.getQubits();
	int firstLength = first.getLength();
	for (int i = 0; i < firstLength; i++) {
		newArray[i] = firstQubits[i];
	}
	
	auto secondQubits = second.getQubits();

	for (int i = 0; i < second.getLength(); i++) {
		newArray[i + firstLength] = secondQubits[i];
	}

	QReg newRegister = QReg(newArray, newRegisterLength);
	return newRegister;
}