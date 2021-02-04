#pragma once

#include "UtilityGates.h"
#include "PauliGates.hpp"
#include "valkNamespace.hpp"
#include "CPUCircuit.h"
#include <chrono>

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
		
		concurrentBlock block1 = concurrentBlock(gates, false);

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

		concurrentBlock block2 = concurrentBlock(gatesBlock2, true);

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
		concurrentBlock block3 = concurrentBlock(gatesBlock3, false);

		std::vector<concurrentBlock> gatesApplied = { block1, block2, block3 };
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
		circ.execute(false);
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << std::endl;
		/*for (int i = 0; i < 4; i++) {
			std::cout << circ.getFinalResults()[i]->getQubitValues()[0] << std::endl;
		}*/
		
	}

	void buildResizableDeutschJozsa(int size) {
		auto begin = std::chrono::high_resolution_clock::now();
		std::vector<bool> wrap;
		for (int i = 0; i < size; i++) {
			if (std::rand() % 2 == 0) {
				wrap.push_back(true);
			}
			else {
				wrap.push_back(false);
			}
		}
		HadamardGate* gq = new HadamardGate();
		PauliX* pal = new PauliX();
		IdentityGate* id = new IdentityGate();
		// Block 1
		std::vector<std::vector<Gate*>> gatesBlock1;
		for (int i = 0; i < size; i++) {
			std::vector<Gate*> qiGatesBlock1;
			if (wrap[i]) {	
				qiGatesBlock1.push_back(gq);
				qiGatesBlock1.push_back(pal);								
			}
			else {
				qiGatesBlock1.push_back(gq);
			}
			gatesBlock1.push_back(qiGatesBlock1);
		}
		std::vector<Gate*> qNGatesBlock1;
		qNGatesBlock1.push_back(pal);
		qNGatesBlock1.push_back(gq);
		gatesBlock1.push_back(qNGatesBlock1);
		concurrentBlock block1 = concurrentBlock(gatesBlock1, false);

		// Block 2
		std::vector<std::vector<Gate*>> gatesBlock2;
		for (int i = 0; i < size; i++) {
			std::vector<Gate*> qiGatesBlock2;
			CNOT* q1CNOT = new CNOT(size);
			qiGatesBlock2.push_back(q1CNOT);
			gatesBlock2.push_back(qiGatesBlock2);
		}
		std::vector<Gate*> qNGatesBlock2;
		qNGatesBlock2.push_back(id);
		gatesBlock2.push_back(qNGatesBlock2);
		concurrentBlock block2 = concurrentBlock(gatesBlock2, true);

		// Block 3
		std::vector<std::vector<Gate*>> gatesBlock3;
		for (int i = 0; i < size; i++) {
			std::vector<Gate*> qiGatesBlock3;
			if (wrap[i]) {
				qiGatesBlock3.push_back(pal);
				qiGatesBlock3.push_back(gq);
			}
			else {
				qiGatesBlock3.push_back(gq);
			}
			gatesBlock3.push_back(qiGatesBlock3);
		}
		std::vector<Gate*> qNGatesBlock3;
		qNGatesBlock3.push_back(id);
		gatesBlock3.push_back(qNGatesBlock3);
		concurrentBlock block3 = concurrentBlock(gatesBlock3, false);

		// Compile blocks
		std::vector<concurrentBlock> gatesApplied = { block1, block2, block3 };
		// Load circuit with gates
		circ.loadGatesApplies(gatesApplied);
		// initialise qubits
		std::vector<Qubit*> startingQubits;
		for (int i = 0; i < size+1; i++) {
			Qubit* newQubit = new Qubit();
			std::vector<valk::ComplexNumber> newVals = { 1, 0 };
			newQubit->safeLoadValues(newVals);
			startingQubits.push_back(newQubit);
		}
		circ.loadStartingPreparations(startingQubits);
		circ.execute(true);
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << std::endl;
	}

};