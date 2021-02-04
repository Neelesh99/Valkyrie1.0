#include "CPUCircuit.h"
#include "UtilityGates.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>

bool dimCheck(std::vector<Qubit*> startingPreparations, std::vector<concurrentBlock> gatesApplied) {
	int qubitBusWidth = startingPreparations.size();
	for (int i = 0; i < gatesApplied.size(); i++) {
		if (gatesApplied[i].getGates().size() != qubitBusWidth) {
			return false;
		}
	}
	return true;
}

void threadedApplyGate(std::vector<Gate*> gates, Qubit* storageLocation) {
	for (int k = 0; k < gates.size(); k++) {
		if (gates[k]->getGateType() == valk::SingleQubit) {
			Qubit* lst[1] = { storageLocation };
			storageLocation = gates[k]->applyGate(lst);
		}
	}
}

void CPUCircuit::execute(bool threading) {
	boost::thread_group tgroup;

	if (dimCheck(startingPreparations, blocks)) {
		for (int i = 0; i < blocks.size(); i++) {
			concurrentBlock block = blocks[i];
			std::vector<std::vector<Gate*>> allGatesInBlock = block.getGates();
			for (int j = 0; j < allGatesInBlock.size(); j++) {
				std::vector<Gate*> fetchGatesForQubit = allGatesInBlock[j];
				if (block.crosstalk || !threading) {
					for (int k = 0; k < fetchGatesForQubit.size(); k++) {
						if (fetchGatesForQubit[k]->getGateType() == valk::SingleQubit) {
							Qubit* lst[1] = { startingPreparations[j] };
							startingPreparations[j] = fetchGatesForQubit[k]->applyGate(lst);
						}
						else if (fetchGatesForQubit[k]->getGateType() == valk::CNot) {
							CNOT castedGate = dynamic_cast<CNOT&>(*fetchGatesForQubit[k]);
							int fetchTargetID = castedGate.getGateTarget();
							Qubit* newArray[2] = { startingPreparations[k], startingPreparations[fetchTargetID] };
							Qubit* newQubit = castedGate.applyGate(newArray);
							startingPreparations[fetchTargetID] = newQubit;
						}
					}
				}
				else {
					tgroup.create_thread(boost::bind(&threadedApplyGate, fetchGatesForQubit, startingPreparations[j]));
				}				
			}
			tgroup.join_all();
		}
		finalState = startingPreparations;
	}
}

