#pragma once

#include "UtilityGates.h"
#include "PauliGates.hpp"
#include "valkNamespace.hpp"
#include "CPUCircuit.h"

enum oracleType {
	balanced = 0,
	constant,
};

class DeutschJozsa {

private:
	CPUCircuit circ;

public:

	void buildDeutschJozsaCircuit() {
		// For now hardcode 3 input DJ
		// First concurrent block
		std::vector<std::vector<Gate*>> gates;
		// q0
		std::vector<Gate*> q0GatesBlock1;
		HadamardGate* gq = new HadamardGate();
		PauliX* pal = new PauliX();
		q0GatesBlock1.push_back(gq);
		q0GatesBlock1.push_back(pal);
		gates.push_back(q0GatesBlock1);
		// q1
		std::vector<Gate*> q1GatesBlock1;
		q1GatesBlock1.push_back(gq);
		gates.push_back(q1GatesBlock1);
		// q2
		std::vector<Gate*> q2GatesBlock1;
		q2GatesBlock1.push_back(gq);
		q2GatesBlock1.push_back(pal);
		gates.push_back(q2GatesBlock1);
		// q3
		std::vector<Gate*> q3GatesBlock1;
		q3GatesBlock1.push_back(pal);
		q3GatesBlock1.push_back(gq);
		gates.push_back(q3GatesBlock1);
		
		concurrentBlock block1 = concurrentBlock(gates);

		// Second Concurrent Block
		std::vector<std::vector<Gate*>> gatesBlock2;
		//q0
		std::vector<Gate*> q0Block2;
		CNOT* q0CNOT = new CNOT(3);
		q0Block2.push_back(q0CNOT);
		gatesBlock2.push_back(q0Block2);
		//q1


		std::vector<concurrentBlock> gatesApplied;
		gatesApplied.push_back(gates);
		circ.loadGatesApplies(gatesApplied);
		std::vector<Qubit*> startingQubits;
		for (int i = 0; i < 4; i++) {
			Qubit* newQubit = new Qubit();
			std::vector<valk::ComplexNumber> newVals = { 1, 0 };
			newQubit->safeLoadValues(newVals);
			startingQubits.push_back(newQubit);
		}
		circ.loadStartingPreparations(startingQubits);
		circ.execute();
		for (int i = 0; i < 4; i++) {
			std::cout << circ.getFinalResults()[i]->getQubitValues()[0] << std::endl;
		}
		std::cout << "Hello There" << std::endl;
	}

};