#pragma once
#include "valkNamespace.hpp"
#include "cuda_runtime.h"
#include "Gate.cuh"


class AbstractGateFactory {

protected:
	valk::executionType computeMode;
	Gate** gates_emitted_;
	int length_ = 1;
	bool empty = true;
public:

	virtual Gate* createNewGate(valk::availableGates gate_type) = 0;
	virtual Gate* createNewGate(valk::availableGates gate_type, valk::ComplexNumber* values) = 0;
};

class CPUGateFactory : public AbstractGateFactory {

private:
	Gate* createNewUGate(valk::ComplexNumber* values);
	Gate* createNewCNOTGate();
	void appendToGates(Gate* val);

public:
	CPUGateFactory() {
		computeMode = valk::executionType::CPU;
		gates_emitted_ = new Gate*[length_];
	}
	Gate* createNewGate(valk::availableGates gate_type);
	Gate* createNewGate(valk::availableGates gate_type, valk::ComplexNumber* values);

	~CPUGateFactory();

};

class GPUGateFactory : public AbstractGateFactory {
private:
	Gate* createNewUGate(valk::ComplexNumber* values);
	Gate* createNewCNOTGate();
	void appendToGates(Gate* val);
public:
	GPUGateFactory() {
		computeMode = valk::executionType::GPU;
		cudaMallocManaged(&gates_emitted_, length_*sizeof(GPUGate*));
	}

	Gate* createNewGate(valk::availableGates gate_type);
	Gate* createNewGate(valk::availableGates gate_type, valk::ComplexNumber* values);

	~GPUGateFactory();
};