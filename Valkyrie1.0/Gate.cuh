#pragma once
#include <vector>
#include "cuda_runtime.h"
#include "valkNamespace.hpp"
#include "QReg.hpp"
#include "Qubit.hpp"


class GateRow {
private:
	valk::ComplexNumber* row_values_;
	int row_dim_;
public:
	GateRow(valk::ComplexNumber* row_values, int row_dim) {
		row_values_ = row_values;
		row_dim_ = row_dim;
	}

	valk::ComplexNumber& operator[](int index) {
		if (index >= 0 && index < row_dim_) {
			return row_values_[index];
		}
	}
};


class Gate {
protected:	
	valk::ComplexNumber* values_;
	GateRow** rows_;
	int* dimensions_;

private:
	void generateRowData() {
		rows_ = allocateRowMemory();
	}
public:
	Gate(){}
	Gate(int* dimensions) {
		dimensions_ = dimensions;
	};
	Gate(int* dimensions, valk::ComplexNumber* values) {
		dimensions_ = dimensions;
		setValues(values);
	}

	void setValues(valk::ComplexNumber* values) {
		values_ = values;
		generateRowData();
	}

	virtual GateRow** allocateRowMemory() = 0;
	
	valk::ComplexNumber* getValues() {
		return values_;
	}

	void setDimensions(int* dimensions) {
		dimensions_ = dimensions;
	}

	int* getDimensions() {
		return dimensions_;
	}

	GateRow& operator[](int index) {
		if (index >= 0 && index < dimensions_[0]) {
			GateRow* rowptr = rows_[index];
			return *rowptr;
		}
		throw std::out_of_range("Index out of range");
	}

};

class CPUGate : public Gate {
public:
	GateRow** allocateRowMemory() {
		int rows = dimensions_[0];
		int cols = dimensions_[1];
		GateRow** arrayOfRows = new GateRow * [rows];
		for (int i = 0; i < rows; i++) {
			GateRow* newCPUMemoryRow = new GateRow(&values_[cols * i], cols);
			arrayOfRows[i] = newCPUMemoryRow;
		}
		rows_ = arrayOfRows;
	}

	~CPUGate() {
		for (int i = 0; i < dimensions_[0]; i++) {
			delete rows_[i];
		}
		delete rows_;
	}
};

class GPUGate : public Gate {
public:
	GateRow** allocateRowMemory() {
		int rows = dimensions_[0];
		int cols = dimensions_[1];
		GateRow** arrayOfRows;
		cudaMallocManaged(&arrayOfRows, rows * sizeof(GateRow*));
		for (int i = 0; i < rows; i++) {
			GateRow* newGPUMemoryRow;
			cudaMallocManaged(&newGPUMemoryRow, sizeof(GateRow));
			newGPUMemoryRow = new(newGPUMemoryRow) GateRow(&values_[cols * i], cols);
			arrayOfRows[i] = newGPUMemoryRow;
		}
		rows_ = arrayOfRows;
	}

	~GPUGate() {
		for (int i = 0; i < dimensions_[0]; i++) {
			cudaFree(rows_[i]);
		}
		cudaFree(rows_);
	}
};

struct qubitGateLine {

	Gate** line_of_gates_;
	int length_;

	qubitGateLine(Gate** line_of_gates, int length) {
		line_of_gates_ = line_of_gates;
	}

	Gate** getAllGates() {
		return line_of_gates_;
	}

	Gate* operator[](int index) {
		if (index >= 0 && index < length_) {
			return line_of_gates_[index];
		}		
	}

};

struct concurrentBlock {
	bool crosstalk;
	qubitGateLine** gatesApplied;
	int length_;
	concurrentBlock(qubitGateLine** gates, int length, bool cross) {
		gatesApplied = gates;
		crosstalk = cross;
		length_ = length;
	}
	qubitGateLine** getGates() {
		return gatesApplied;
	}

	qubitGateLine* operator[](int index) {
		if (index >= 0 && index < length_) {
			return gatesApplied[index];
		}		
	}
};