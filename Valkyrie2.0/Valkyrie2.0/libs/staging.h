#pragma once
#include <iostream>
#include <vector>
#include "BaseTypes.h"

/*
	Stager.h
	Description: File provides interface for functions needed for staging functionality

*/

class Stager {
private:
	std::vector<Register> registers_;
	std::vector<GateRequest> gates_;
	std::vector<ConcurrentBlock> blocks_;

	bool loadRegisters(std::vector<Register> registers) {
		registers_ = registers;
		return true;
	}

	bool loadGates(std::vector<GateRequest> requests) {
		gates_ = requests;
		return true;
	}

	// concurrencyCalc can calculate whether we need a break for concurrency
	//  then loads the appropriate gates into each block
	bool concurrencyCalc() {
		ConcurrentBlock block(0);
		for (auto gateR : gates_) {
			if (gateR.getGateDim() == 1) {
				block.addGate(gateR);
			}
			else {
				if (block.getCount() > 0) {
					blocks_.push_back(block);
				}
				ConcurrentBlock tempBlock(0);
				tempBlock.addGate(gateR);
				blocks_.push_back(tempBlock);
				block = ConcurrentBlock(0);
			}
		}
		if (block.getCount() > 0) {
			blocks_.push_back(block);
		}
		return true;
	}
	
public:
	Stager() {

	}
	Stager(std::vector<Register> registers, std::vector<GateRequest> requests) {
		loadRegisters(registers);
		loadGates(requests);
		concurrencyCalc();
	}
	std::vector<ConcurrentBlock> stageInformation(std::vector<Register> registers, std::vector<GateRequest> requests) {
		loadRegisters(registers);
		loadGates(requests);
		concurrencyCalc();
		return blocks_;
	}
	std::vector<ConcurrentBlock> getConcurrencyBlocks() {
		return blocks_;
	}

	std::vector<Register> getRegisters() {
		return registers_;
	}
	
};
