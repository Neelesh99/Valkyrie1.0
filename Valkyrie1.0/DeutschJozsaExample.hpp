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
		auto begin = std::chrono::high_resolution_clock::now();

		// code to benchmark

		
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
		std::vector<Gate*> q1Block2;
		CNOT* q1CNOT = new CNOT(3);
		q1Block2.push_back(q1CNOT);
		gatesBlock2.push_back(q1Block2);
		//q2
		std::vector<Gate*> q2Block2;
		CNOT* q2CNOT = new CNOT(3);
		q2Block2.push_back(q2CNOT);
		gatesBlock2.push_back(q2Block2);		
		//q3
		IdentityGate* id = new IdentityGate();
		std::vector<Gate*> q3Block2;
		q3Block2.push_back(id);
		gatesBlock2.push_back(q3Block2);

		concurrentBlock block2 = concurrentBlock(gatesBlock2);

		// Third Concurrent Block
		std::vector<std::vector<Gate*>> gatesBlock3;
		// q0
		std::vector<Gate*> q0GatesBlock3;
		q0GatesBlock3.push_back(pal);
		q0GatesBlock3.push_back(gq);
		gatesBlock3.push_back(q0GatesBlock3);
		// q1
		std::vector<Gate*> q1GatesBlock3;
		q1GatesBlock3.push_back(gq);
		gatesBlock3.push_back(q1GatesBlock3);
		// q2
		std::vector<Gate*> q2GatesBlock3;
		q2GatesBlock3.push_back(pal);
		q2GatesBlock3.push_back(gq);
		gatesBlock3.push_back(q2GatesBlock3);
		// q3
		std::vector<Gate*> q3GatesBlock3;
		
		q3GatesBlock3.push_back(id);
		gatesBlock3.push_back(q3GatesBlock3);
		concurrentBlock block3 = concurrentBlock(gatesBlock3);


		std::cout << "Hello There" << std::endl;

		std::vector<concurrentBlock> gatesApplied = { gates, gatesBlock2, gatesBlock3};
		circ.loadGatesApplies(gatesApplied);
		std::vector<Qubit*> startingQubits;
		for (int i = 0; i < 3; i++) {
			Qubit* newQubit = new Qubit();
			std::vector<valk::ComplexNumber> newVals = { 1, 0 };
			newQubit->safeLoadValues(newVals);
			startingQubits.push_back(newQubit);
		}
		Qubit* newQubit = new Qubit();
		std::vector<valk::ComplexNumber> newVals = { 0, 1 };
		newQubit->safeLoadValues(newVals);
		startingQubits.push_back(newQubit);
		circ.loadStartingPreparations(startingQubits);
		circ.execute();
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << circ.getFinalResults()[i]->getQubitValues()[0] << std::endl;
		}
		
	}

};