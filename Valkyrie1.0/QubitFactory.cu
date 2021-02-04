#include "QubitFactory.cuh"

Qubit* CPUQubitFactory::generateBlankQubit() {
	Qubit* quPointer;
	quPointer = new Qubit();
	if (empty) {
		qubitTracker_[0] = quPointer;
		empty = false;
	}
	else {
		Qubit** newtracker = new Qubit * [trackerSize + 1];
		memcpy(newtracker, qubitTracker_, trackerSize);
		Qubit** oldtracker = qubitTracker_;
		newtracker[trackerSize] = quPointer;
		trackerSize++;
		qubitTracker_ = newtracker;
		delete oldtracker;
	}
	int* dims = new int[2] {2, 1};
	quPointer->setQubitDimensions(dims);
	valk::ComplexNumber* values = new valk::ComplexNumber[2]{ 0,0 };
	default0_ ? values[0] = 1 : values[1] = 1;
	quPointer->safeLoadValues(values);
	return quPointer;
}

CPUQubitFactory::~CPUQubitFactory() {
	if (empty) {
		delete qubitTracker_;
	}
	else {
		for (int i = 0; i < trackerSize; i++) {
			Qubit* resolvedQubit = qubitTracker_[i];
			delete resolvedQubit->getQubitValues();
			delete resolvedQubit->getQubitDimensions();
			delete resolvedQubit;
		}
		delete qubitTracker_;
	}
}

Qubit* GPUQubitFactory::generateBlankQubit() {
	Qubit* quPointer;
	cudaMallocManaged(&quPointer, sizeof(Qubit));
	if (empty) {
		qubitTracker_[0] = quPointer;
		empty = false;
	}
	else {
		Qubit** newtracker;
		cudaMallocManaged(&newtracker, (trackerSize+1)*sizeof(Qubit*));
		cudaMemcpy(newtracker, qubitTracker_, trackerSize, cudaMemcpyDefault);
		Qubit** oldtracker =  qubitTracker_;
		newtracker[trackerSize] = quPointer;
		trackerSize++;
		qubitTracker_ = newtracker;
		cudaFree(oldtracker);
	}
	int* dims;
	cudaMallocManaged(&dims, 2 * sizeof(int));
	dims[0] = 2;
	dims[1] = 1;
	quPointer->setQubitDimensions(dims);
	valk::ComplexNumber* values;
	cudaMallocManaged(&values, 2 * sizeof(valk::ComplexNumber));
	values[0] = 0;
	values[1] = 0;
	default0_ ? values[0] = 1 : values[1] = 1;
	quPointer->safeLoadValues(values);
	return quPointer;
}

GPUQubitFactory::~GPUQubitFactory() {
	if (empty) {
		cudaFree(qubitTracker_);
	}
	else {
		for (int i = 0; i < trackerSize; i++) {
			Qubit* resolvedQubit = qubitTracker_[i];
			cudaFree(resolvedQubit->getQubitValues());
			cudaFree(resolvedQubit->getQubitDimensions());
			cudaFree(resolvedQubit);
		}
		cudaFree(qubitTracker_);
	}
}

