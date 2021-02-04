#pragma once
#include "valkNamespace.hpp"
#include "Qubit.hpp"
#include "cuda_runtime.h"
#include <stdexcept>
#include <vector>

class QubitFactory {
protected:
	bool default0_ = true;

public:
	virtual Qubit* generateBlankQubit() = 0;
};

class CPUQubitFactory : public QubitFactory {

private:
	bool empty = true;
	Qubit** qubitTracker_;
	int trackerSize = 1;
	
public:
	CPUQubitFactory(bool defaultAt0) {
		default0_ = defaultAt0;
		qubitTracker_ = new Qubit * [trackerSize];
	}
	Qubit* generateBlankQubit();

	~CPUQubitFactory();

};

class GPUQubitFactory : public QubitFactory {

private:
	bool empty = true;
	Qubit** qubitTracker_;
	int trackerSize = 1;

public:

	GPUQubitFactory(bool defaultAt0) {
		default0_ = defaultAt0;
		cudaMallocManaged(&qubitTracker_, trackerSize * sizeof(Qubit*));
	}

	Qubit* generateBlankQubit();

	~GPUQubitFactory();

};