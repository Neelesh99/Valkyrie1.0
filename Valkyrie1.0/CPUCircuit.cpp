#include "CPUCircuit.h"
#include "UtilityGates.h"

bool dimCheck(std::vector<Qubit*> startingPreparations, std::vector<concurrentBlock> gatesApplied) {
	int qubitBusWidth = startingPreparations.size();
	for (int i = 0; i < gatesApplied.size(); i++) {
		if (gatesApplied[i].getGates().size() != qubitBusWidth) {
			return false;
		}
	}
	return true;
}

void CPUCircuit::execute() {
	if (dimCheck(startingPreparations, blocks)) {
		for (int i = 0; i < blocks.size(); i++) {
			concurrentBlock block = blocks[i];
			std::vector<std::vector<Gate*>> allGatesInBlock = block.getGates();
			for (int j = 0; j < allGatesInBlock.size(); j++) {
				std::vector<Gate*> fetchGatesForQubit = allGatesInBlock[j];
				for (int k = 0; k < fetchGatesForQubit.size(); k++) {
					if (fetchGatesForQubit[k]->getGateType() == valk::SingleQubit) {
						Qubit* lst[1] = { startingPreparations[j] };
						startingPreparations[j] = fetchGatesForQubit[k]->applyGate(lst);
					}
					else if (fetchGatesForQubit[k]->getGateType() == valk::CNot) {
						CNOT castedGate = dynamic_cast<CNOT&>(*fetchGatesForQubit[k]);
						int fetchTargetID = castedGate.getGateTarget();
						Qubit* newArray[2] = { startingPreparations[k], startingPreparations[fetchTargetID]};
						Qubit* newQubit = castedGate.applyGate(newArray);
						startingPreparations[fetchTargetID] = newQubit;
					}
				}
			}
		}
		finalState = startingPreparations;
	}
}

