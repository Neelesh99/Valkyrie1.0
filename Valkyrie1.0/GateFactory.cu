#include "GateFactory.cuh"

// CPU Gate Factory
Gate* CPUGateFactory::createNewCNOTGate() {
	int* dimensions = new int[2]{ 4,4 };
	Gate* CNOTCandidate = new CPUGate();
	CNOTCandidate->setDimensions(dimensions);
	valk::ComplexNumber* values = new valk::ComplexNumber[16]{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 0, 1,
		0, 0, 1, 0
	};
	CNOTCandidate->setValues(values);
	return CNOTCandidate;
}

Gate* CPUGateFactory::createNewUGate(valk::ComplexNumber* values) {
	int* dimensions = new int[2]{ 2,2 };
	Gate* UGateCandidate = new CPUGate();
	UGateCandidate->setDimensions(dimensions);
	UGateCandidate->setValues(values);
	return UGateCandidate;
}

void CPUGateFactory::appendToGates(Gate* val) {
	if (empty) {
		gates_emitted_[0] = val;
		empty = false;
	}
	else {
		Gate** newGateList = new Gate * [length_ + 1];
		memcpy(newGateList, gates_emitted_, length_);
		Gate** oldTracker = gates_emitted_;
		newGateList[length_] = val;
		length_++;
		gates_emitted_ = newGateList;
		delete oldTracker;
	}
}

Gate* CPUGateFactory::createNewGate(valk::availableGates gate_types) {
	Gate* returnGate = createNewCNOTGate();
	switch (gate_types) {
	case valk::availableGates::CNOT:		
		appendToGates(returnGate);
		return returnGate;
		break;
	case valk::availableGates::U:
		throw std::invalid_argument("Expected list of initialised values for U gate");
		break;
	default:
		throw std::invalid_argument("Gate not supported");
	}
}

Gate* CPUGateFactory::createNewGate(valk::availableGates gate_types, valk::ComplexNumber* values) {
	Gate* returnGate = createNewUGate(values);
	switch (gate_types) {
	case valk::availableGates::CNOT:
		throw std::invalid_argument("Expected no initialised values for CNOT gate");
		break;
	case valk::availableGates::U:		
		appendToGates(returnGate);
		return returnGate;
		break;
	default:
		throw std::invalid_argument("Gate not supported");
	}
}

CPUGateFactory::~CPUGateFactory() {
	if (empty) {
		delete gates_emitted_;
		return;
	}
	// Delete gate data
	for (int i = 0; i < length_; i++) {
		Gate* resolved_ptr = gates_emitted_[i];
		delete resolved_ptr->getDimensions();
		delete resolved_ptr->getValues();
		delete resolved_ptr;
	}
	delete gates_emitted_;
}

//GPU Gate Factory
Gate* GPUGateFactory::createNewCNOTGate() {
	int* dimensions;
	cudaMallocManaged(&dimensions, 2 * sizeof(int));
	dimensions[0] = 4;
	dimensions[1] = 4;
	Gate* CNOTCandidate;
	cudaMallocManaged(&CNOTCandidate, sizeof(GPUGate));
	CNOTCandidate = new(CNOTCandidate) GPUGate();
	CNOTCandidate->setDimensions(dimensions);
	valk::ComplexNumber* values;
	cudaMallocManaged(&values, 16 * sizeof(valk::ComplexNumber));
	valk::ComplexNumber values_const[] = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 0, 1,
		0, 0, 1, 0
	};
	for (int i = 0; i < 16; i++) {
		values[i] = values_const[i];
	}
	CNOTCandidate->setValues(values);
	return CNOTCandidate;
}

Gate* GPUGateFactory::createNewUGate(valk::ComplexNumber* values) {
	int* dimensions;
	cudaMallocManaged(&dimensions, 2 * sizeof(int));
	dimensions[0] = 2;
	dimensions[1] = 2;
	Gate* UGateCandidate;
	cudaMallocManaged(&UGateCandidate, sizeof(GPUGate));
	UGateCandidate = new(UGateCandidate) GPUGate();
	UGateCandidate->setDimensions(dimensions);
	UGateCandidate->setValues(values);
	return UGateCandidate;
}

void GPUGateFactory::appendToGates(Gate* val) {
	if (empty) {
		gates_emitted_[0] = val;
		empty = false;
	}
	else {
		Gate** newGateList;
		cudaMallocManaged(newGateList, (length_ + 1) * sizeof(Gate*));
		cudaMemcpy(newGateList, gates_emitted_, length_, cudaMemcpyDefault);
		Gate** oldTracker = gates_emitted_;
		newGateList[length_] = val;
		length_++;
		gates_emitted_ = newGateList;
		cudaFree(oldTracker);
	}
}

Gate* GPUGateFactory::createNewGate(valk::availableGates gate_types) {
	Gate* returnGate = createNewCNOTGate();
	switch (gate_types) {
	case valk::availableGates::CNOT:		
		appendToGates(returnGate);
		return returnGate;
		break;
	case valk::availableGates::U:
		throw std::invalid_argument("Expected list of initialised values for U gate");
		break;
	default:
		throw std::invalid_argument("Gate not supported");
	}
}

Gate* GPUGateFactory::createNewGate(valk::availableGates gate_types, valk::ComplexNumber* values) {
	Gate* returnGate = createNewUGate(values);
	switch (gate_types) {
	case valk::availableGates::CNOT:
		throw std::invalid_argument("Expected no initialised values for CNOT gate");
		break;
	case valk::availableGates::U:		
		appendToGates(returnGate);
		return returnGate;
		break;
	default:
		throw std::invalid_argument("Gate not supported");
	}
}

GPUGateFactory::~GPUGateFactory() {
	if (empty) {
		cudaFree(gates_emitted_);
		return;
	}
	// Delete gate data
	for (int i = 0; i < length_; i++) {
		Gate* resolved_ptr = gates_emitted_[i];
		cudaFree(resolved_ptr->getDimensions());
		cudaFree(resolved_ptr->getValues());
		cudaFree(resolved_ptr);
	}
	cudaFree(gates_emitted_);
}


