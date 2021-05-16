#pragma once
#include <vector>
#include <string>
#include <complex>
#include <map>
#include <iostream>

struct idLocationPairs {
	std::vector<std::string> identifiers;
	std::vector<int> locations;
	int getSize() {
		return identifiers.size();
	}
};

struct SVPair {
	std::string name_;
	int location_;
	SVPair(std::string name, int location) {
		name_ = name;
		location_ = location;
	}
	bool areEqual(SVPair comp) {
		return comp.location_ == location_ && comp.name_ == name_;
	}
};

enum DeviceType {
	CPU_,
	GPU_,
	INVALID
};

class HeaderData {
private:
	double openQASMStandard_ = 0.0;
	std::vector<std::string> includeFiles_;
public:
	HeaderData(std::string value, std::vector<std::string> includes) {
		openQASMStandard_ = std::stod(value);
		includeFiles_ = includes;
	}
};

enum RegisterType {
	quantum_,
	classical_,
	invalid_
};



class QuantumRegister {
private:
	std::string identifier_;
	int width_;
public:
	QuantumRegister(std::string identifier, int width) {
		identifier_ = identifier;
		width_ = width;
	}
	std::string getIdentifier() {
		return identifier_;
	}
	int getWidth() {
		return width_;
	}
	bool isQubit() {
		return width_ == 1;
	}
	QuantumRegister() = default;
};

class ClassicalRegister {
private:
	std::string identifier_;
	int width_;
	std::vector<int> values_;
public:
	ClassicalRegister(std::string identifier, int width) {
		identifier_ = identifier;
		width_ = width;
		for (int i = 0; i < width; i++) {
			values_.push_back(0);
		}
	}
	std::string getIdentifier() {
		return identifier_;
	}
	int getWidth() {
		return width_;
	}
	void setValue(int i, int val) {
		values_[i] = val;
	}
	int getValue(int i) {
		return values_[i];
	}
	ClassicalRegister() = default;
};

class Register {
private:
	RegisterType regType_;
	QuantumRegister qReg_;
	ClassicalRegister cReg_;
public:
	Register(RegisterType type, QuantumRegister qreg) {
		regType_ = type;
		qReg_ = qreg;
	}
	Register(RegisterType type, ClassicalRegister creg) {
		regType_ = type;
		cReg_ = creg;
	}

	QuantumRegister getQuantumRegister() {
		return qReg_;
	}

	ClassicalRegister getClassicalRegister() {
		return cReg_;
	}

	void setClassicalRegister(ClassicalRegister cReg) {
		cReg_ = cReg;
	}

	std::string getName() {
		if (regType_ == quantum_) {
			return qReg_.getIdentifier();
		}
		else {
			return cReg_.getIdentifier();
		}
	}

	bool isQuantum() {
		return regType_ == quantum_;
	}
};



enum GateRequestType {
	I,
	U,
	CX,
	h,
	cx,
	u3,
	u2,
	u1,
	id,
	u0,
	u,
	p,
	x,
	y,
	z,
	s,
	sdg,
	t,
	tdg,
	rx,
	ry,
	rz,
	sx,
	sxdg,
	cz,
	cy,
	swap,
	ch,
	ccx,
	cswap,
	crx,
	cry,
	crz,
	cu1,
	cp,
	cu3,
	csx,
	cu,
	rxx,
	rzz,
	rccx,
	rc3x,
	c3x,
	c3sqrtx,
	c4x,
	CUSTOM
};

class GateRequest {
private:
	GateRequestType gateType_;
	std::vector<std::string> registerIdentifiers_;
	std::vector<int> locations_;
	std::vector<double> parameters_;

public:
	GateRequest(){}
	GateRequest(GateRequestType type) {
		gateType_ = type;
	}
	void addressQubit(std::string registerID, int location) {
		registerIdentifiers_.push_back(registerID);
		locations_.push_back(location);
	}
	void setParameters(std::vector<double> params) {
		parameters_ = params;
	}
	void addParameter(double value) {
		parameters_.push_back(value);
	}
	int getGateDim() {
		return registerIdentifiers_.size();
	}
	std::vector<std::string> getRegisters() {
		return registerIdentifiers_;
	}
	std::vector<int> getLocations() {
		return locations_;
	}
	GateRequestType getGateType() {
		return gateType_;
	}
	std::vector<double> getParameters() {
		return parameters_;
	}
};

class ConcurrentBlock {
private:
	int count_ = 0;
	std::vector<GateRequest> gates_;
public:
	ConcurrentBlock(int count) {
	}
	void addGate(GateRequest newGate) {
		gates_.push_back(newGate);
		count_++;
	}
	void setCount(int count) {
		count_ = count;
	}
	int getCount() {
		return count_;
	}
	std::vector<GateRequest> getGates() {
		return gates_;
	}
};

class Qubit {
private:
	std::complex<double>* s_0;
	std::complex<double>* s_1;
public:
	Qubit(std::complex<double>* s0, std::complex<double>* s1) {
		s_0 = s0;
		s_1 = s1;
	}

	std::complex<double>* fetch(int i) {
		if (i == 0) {
			return s_0;
		}
		else {
			return s_1;
		}
	}
};

class Gate {
private:
	// std::complex<double>* gateArray_; for next iteration
	std::vector<std::vector<std::complex<double>>> gateArray_;
	int m_;	// dimensions
	int n_;
public:
	Gate(int m, int n, std::vector<std::vector<std::complex<double>>> gateArray) {
		m_ = m;
		n_ = n;
		gateArray_ = gateArray;
	}
	std::complex<double> fetchValue(int x, int y) {
		/*if (x < m_ && y < n_) {
			int index = x * m_ + y;
			return &gateArray_[index];
		}
		else {
			return nullptr;
		}*/
		return gateArray_[x][y];
	}
	int getM() {
		return m_;
	}
	int getN() {
		return n_;
	}

};

class Calculation {
private:
	Gate* gate_;
	//std::complex<double>* qubitValues_; next iteration
	std::vector<Qubit*> qubitValues_;
	std::vector<SVPair> locations_;
public:
	Calculation(Gate* gate, std::vector<Qubit*> qubitVals, std::vector<SVPair> locations) {
		gate_ = gate;
		qubitValues_ = qubitVals;
		locations_ = locations;
	}
	Gate* getGate() {
		return gate_;
	}
	Qubit* getQubit(int i) {
		return qubitValues_[i];
	}

	std::vector<SVPair> getLocations() {
		return locations_;
	}
	std::vector<SVPair> getNewOrder(std::vector<SVPair> oldOrder) {
		if (locations_.size() != 2) {
			return oldOrder;
		}
		std::vector<SVPair> newOrder;
		for (int i = 0; i < oldOrder.size(); i++) {
			if (!locations_[0].areEqual(oldOrder[i]) && !locations_[1].areEqual(oldOrder[i])) {
				newOrder.push_back(oldOrder[i]);
			}
		}
		newOrder.push_back(locations_[0]);
		newOrder.push_back(locations_[1]);
		return newOrder;
	}

	std::vector<Qubit*> getQubits() {
		return qubitValues_;
	}
};

class MeasureCommand {
private:
	idLocationPairs from_;
	idLocationPairs to_;
public:
	MeasureCommand(idLocationPairs from, idLocationPairs to) {
		from_ = from;
		to_ = to;
	}

	idLocationPairs getFrom() {
		return from_;
	}

	idLocationPairs getTo() {
		return to_;
	}
};



class StateVector {
private:
	std::vector<SVPair> positions_;
	std::vector<std::complex<double>> state_;
	std::map<std::string, std::vector<Qubit*>>* qubitMap_;
	StateVector* reordered_;
	bool isReorder = false;

	int inverseTail(int nTotal, int indexInPositions, int locationInStateVec) {
		int j = std::pow(2, (nTotal - indexInPositions));
		if ((locationInStateVec % j) < (j / 2)) {
			return 0;
		}
		else {
			return 1;
		}
	}

	bool tail(int nTotal, int indexInPositions, int locationInStateVec, int index) {
		return inverseTail(nTotal, indexInPositions, locationInStateVec) == index;
	}

	std::vector<int> affectedValues(int loc1, int index1, int loc2, int index2) {
		std::vector<int> affected;
		int n = positions_.size();
		for (int i = 0; i < state_.size(); i++) {
			if (tail(n, loc1, i, index1) && tail(n, loc2, i, index2)) {
				affected.push_back(i);
			}
		}
		return affected;
	}

	void calculateNewVals(int pos1, int pos2, std::vector<std::complex<double>> newValues, int loc1Index, int loc2Index) {
		int pos = pos1 * 2 + pos2;
		std::complex<double> newVal = newValues[pos];
		std::vector<int> affected = affectedValues(loc1Index, pos1, loc2Index, pos2);
		int n = positions_.size();
		for (int position : affected) {
			std::complex < double> val = newVal;
			for (int i = 0; i < positions_.size(); i++) {				
				if (i != loc1Index && i != loc2Index) {
					int tailedPos = inverseTail(n, i, position);					
					std::complex<double> value = *(qubitMap_->find(positions_[i].name_)->second[positions_[i].location_]->fetch(tailedPos));
					val = val * value;
				}
			}
			state_[position] = val;
		}
	}

	int searchIndex(SVPair val) {
		for (int i = 0; i < positions_.size(); i++) {
			SVPair res = positions_[i];
			if (res.name_ == val.name_ && res.location_ == val.location_) {
				return i;
			}
		}
		return -1;
	}

	int searchIndex(SVPair val, std::vector<SVPair> positions) {
		for (int i = 0; i < positions.size(); i++) {
			SVPair res = positions[i];
			if (res.name_ == val.name_ && res.location_ == val.location_) {
				return i;
			}
		}
		return -1;
	}

	std::vector<int> mapToOldScheme(std::vector<int> values, std::vector<SVPair> newScheme, std::vector<SVPair> oldScheme) {
		std::vector<int> oldValues;
		int n = values.size();
		oldValues.resize(n);
		for (int i = 0; i < n; i++) {
			oldValues[i] = values[searchIndex(oldScheme[i], newScheme)];
		}
		return oldValues;
	}

	int resolvePosition(std::vector<int> values) {
		int n = values.size();
		int position = 0;
		for (int i = 0; i < n; i++) {
			int j = n - i;
			int val = values[i] * std::pow(2, j - 1);
			position += val;
		}
		return position;
	}

public:
	StateVector() {};
	StateVector(std::map<std::string, std::vector<Qubit*>>* linkToQubits) {
		qubitMap_ = linkToQubits;
		initialiseReorder();
	}

	std::vector<std::complex<double>> getState() {
		return state_;
	}

	void initialiseReorder() {
		reordered_ = new StateVector();
		reordered_->setReorder(true);
	}

	void setReorder(bool reorder) {
		isReorder = reorder;
	}

	void tensorProduct() {
		for (std::map<std::string, std::vector<Qubit*>>::iterator it = qubitMap_->begin(); it != qubitMap_->end(); ++it) {
			for (int i = 0; i < it->second.size(); i++) {
				SVPair pair(it->first, i);
				positions_.push_back(pair);
			}
		}
		int n = positions_.size();
		int dimStateVec = std::pow(2, n);
		state_.resize(dimStateVec);
		for (int i = 0; i < dimStateVec; i++) {
			std::complex<double> start = 1;
			for (int j = 0; j < n; j++) {
				int element = inverseTail(n, j, i);
				SVPair resolvedPair = positions_[j];
				Qubit* qubit = qubitMap_->find(resolvedPair.name_)->second[resolvedPair.location_];
				start = start * *(qubit->fetch(element));
			}
			state_[i] = start;
		}
	}

	// Will only be called during reordering
	void tensorProduct(std::vector<SVPair> newOrder, std::vector<SVPair> oldOrder, std::vector<std::complex<double>> oldState) {
		positions_ = newOrder;
		int n = positions_.size();
		int dimStateVec = std::pow(2, n);
		state_.resize(dimStateVec);
		
		for (int i = 0; i < dimStateVec; i++) {
			std::vector<int> newSchemeVals;
			for (int j = 0; j < n; j++) {
				newSchemeVals.push_back(inverseTail(n, j, i));
			}
			std::vector<int> oldSchemeVals = mapToOldScheme(newSchemeVals, newOrder, oldOrder);
			state_[i] = oldState[resolvePosition(oldSchemeVals)];
		}

	}

	void modifyState(std::vector<std::complex<double>> newValues, SVPair loc1, SVPair loc2) {
		int loc1Index = searchIndex(loc1);
		int loc2Index = searchIndex(loc2);
		if (loc1Index == -1 || loc2Index == -1) {
			return;
		}
		if (newValues.size() != 4) {
			return;
		}
		calculateNewVals(0, 0, newValues, loc1Index, loc2Index);
		calculateNewVals(0, 1, newValues, loc1Index, loc2Index);
		calculateNewVals(1, 0, newValues, loc1Index, loc2Index);
		calculateNewVals(1, 1, newValues, loc1Index, loc2Index);
	}

	void quickRefresh() {
		int n = positions_.size();
		int dimStateVec = std::pow(2, n);
		for (int i = 0; i < dimStateVec; i++) {
			std::complex<double> start = 1;
			for (int j = 0; j < n; j++) {
				int element = inverseTail(n, j, i);
				SVPair resolvedPair = positions_[j];
				Qubit* qubit = qubitMap_->find(resolvedPair.name_)->second[resolvedPair.location_];
				start = start * *(qubit->fetch(element));
			}
			state_[i] = start;
		}
	}

	int getVal(int positionInStateVector, SVPair pair) {
		int position = searchIndex(pair);
		return inverseTail(positions_.size(), position, positionInStateVector);
	}

	StateVector* reorder(std::vector<SVPair> newOrder) {		
		reordered_->tensorProduct(newOrder, positions_, state_);
		return reordered_;
	}

	std::vector<SVPair> getOrder() {
		return positions_;
	}

	~StateVector() {
		if (!isReorder) {
			delete reordered_;
		}
	}
};