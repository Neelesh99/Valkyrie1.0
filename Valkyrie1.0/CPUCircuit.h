#pragma once
#include <vector>
#include "Gate.hpp"



class CPUCircuit {

private:
	std::vector<Qubit*> startingPreparations;
	std::vector<concurrentBlock> blocks;
	std::vector<Qubit*> finalState;
public:
	CPUCircuit(){
	}
	void loadStartingPreparations(std::vector<Qubit*> values) {
		startingPreparations = values;
	}
	void loadGatesApplies(std::vector<concurrentBlock> values) {
		blocks = values;
	}
	std::vector<Qubit*> getStartingPreparations() {
		return startingPreparations;
	}
	std::vector<concurrentBlock> getGatesPrepared() {
		return blocks;
	}
	void execute(bool threading);
	std::vector<Qubit*> getFinalResults() {
		return finalState;
	}
};