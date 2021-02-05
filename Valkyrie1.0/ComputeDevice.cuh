#pragma once
#include "cuda_runtime.h"
#include "valkNamespace.hpp"
#include "QubitFactory.cuh"
#include "TensorProduct.cuh"
#include "Qubit.hpp"

typedef EntangledQubits* (*tensorProductFunction)(Qubit a, Qubit b);

class AbstractComputeDevice {
protected:
	valk::executionType computeMode;
	QubitFactory* qubitFactory;
	tensorProductFunction tensorProductEvaluation;
public:

	virtual QubitFactory* fetchQubitFactory() = 0;
	virtual tensorProductFunction fetchTensorProductFunction() = 0;

};

class CPUComputeDevice : public AbstractComputeDevice {
public:

	CPUComputeDevice() {
		computeMode = valk::executionType::CPU;
		qubitFactory = new CPUQubitFactory(true);
		tensorProductEvaluation = tensorProductCPU;
	}

	QubitFactory* fetchQubitFactory() {
		return qubitFactory;
	}

	tensorProductFunction fetchTensorProductFunction() {
		return tensorProductEvaluation;
	}
};

class GPUComputeDevice : public AbstractComputeDevice {
public:

	GPUComputeDevice() {
		computeMode = valk::executionType::GPU;
		qubitFactory = new GPUQubitFactory(true);
		tensorProductEvaluation = tensorProductGPU;
	}

	QubitFactory* fetchQubitFactory() {
		return qubitFactory;
	}

	tensorProductFunction fetchTensorProductFunction() {
		return tensorProductEvaluation;
	}
};