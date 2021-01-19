#pragma once

#include "valkNamespace.hpp"
#include "Qubit.hpp"


class QReg {

private:
	Qubit* qubits;
	int registerLength = 0;

	void push_(Qubit newEntry);
	QReg addRegisters_(QReg first, QReg second);
public:

	QReg(int initialLength) {
		registerLength = initialLength;
	};
	QReg(Qubit* insertQubits, int size) {
		qubits = insertQubits;
		registerLength = size;
	}

	void setQubits(Qubit* inputQubits) {
		qubits = inputQubits;
	}

	Qubit* getQubits() {
		return qubits;
	}

	int getLength() {
		return registerLength;
	}

	void push(Qubit newVal) {
		push_(newVal);
	}

	QReg operator + (QReg obj) {
		return addRegisters_(*this, obj);
	}
};