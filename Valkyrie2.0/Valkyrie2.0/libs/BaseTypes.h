#pragma once
#include <vector>
#include <string>
#include <complex>
#include <map>
#include <iostream>

/*
	BaseTypes.h
	Description: Defines all common datatypes used throughout the codebase

	Defined Classes:
	idLocationPairs
	SVPair
	expEval
	doubleOrArg
	gateDeclaration
	gateOp
	DeviceType
	HeaderData
	RegisterType
	QuantumRegister
	ClassicalRegister
	Register
	GateRequestType
	GateRequest
	ConcurrentBlock
	Qubit
	Gate
	Calculation
	MeasureCommand
	StateVector
*/

// idLocationPairs is a datastructure used extensively in the parsing stage of Valkyrie, used to relate
// which exact qubit(s) a particular gate is supposed to be operating on.
struct idLocationPairs {
	std::vector<std::string> identifiers;
	std::vector<int> locations;
	int getSize() {
		return identifiers.size();
	}
};

// SVPair similar ot idLocationPairs but to be used exclusively in statevector manipulation. The SVPair
// datastructure is used as a key when navigating the various combination of states in the Statevector.
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

// expEval used in the parsing of custom gate definitions, allows the program to distinguish between a 
// variable or constant being used as input in a gate.
struct expEval {
	std::string ident;
	double value;
	bool identNotVal;
};

// doubleOrArg conversion of an expEval into an expression of which position in a variable list to get
// a parameter or the constant value of the parameter provided in gate definition.
struct doubleOrArg {
	bool doubleNotArg;
	double valD;
	int position;
};

// gateDeclaration datastructure to be used to carry custom gate declaration header after parsing.
struct gateDeclaration {
	std::string gateName;
	std::vector<std::string> idLocList;
	std::vector<std::string> paramList;
};

// gateOp datastructure to hold representation of a gate operation in a custom gate, uses the
// expVal datastructrure to differentiate between constant parameters and required parameters
struct gateOp {
	std::string gateName;
	std::vector<expEval> params;
	std::vector<std::string> idLocs;
};

// DeviceType enumeration of what kind of device we are using to run quantum simulations.
enum DeviceType {
	CPU_,
	GPU_,
	INVALID
};

// HeaderData datastructure to hold header data provided in the OPENQASM standard.
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

// RegisterType enumeration for what kind of register is being instantiated.
enum RegisterType {
	quantum_,
	classical_,
	invalid_
};

// QuantumRegister datastructure to hold a parsed representation of a quantum register.
// This datastructure holds no qubits, but will be used by the staging module to 
// generate qubit construction instructions.
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

// QuantumRegister datastructure to hold a parsed representation of a classical register.
// This datastructure does hold classical bits via the int representation.
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

// Register is a wrapper for Quantum and Classical registers, allowing the staging module
// to differentiate between the two.
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

// GateRequestType defines an enumeration for the primitive gate types U and CX as well
// as all qeLib1 gates. Allowing for efficient compilation
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

// GateRequest is a datastructure to represent a user commanded gate operation, will be used by 
// computation device to generate the gate matrices itself
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

// ConcurrentBlock represent a block of gates which cna be processed in parallel without affecting 
// accuracy of the computation. Used by staging module to send gates to Device
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

// Qubit is the basic Qubit representation which is used to initially store qubit values. If 
// Valkyrie is in fast computation mode then Qubit's are used exclusively to store the idividual states
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

// Gate provides a basic gate representation for the computation device to perform matrix operations.
// If Valkyrie is in fast computation mode then the Gate matrix is directly used for computation.
class Gate {
private:
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
		return gateArray_[x][y];
	}
	std::vector<std::vector<std::complex<double>>> getArray() {
		return gateArray_;
	}
	int getM() {
		return m_;
	}
	int getN() {
		return n_;
	}

};

// Calculation is a class which is used by both fast and statevector computation modes
// It holds the primitive gate and qubit values or state vector locations that are used
// by the matrix processing modules.
class Calculation {
private:
	Gate* gate_;
	std::vector<Qubit*> qubitValues_;
	std::vector<SVPair> locations_;
	
	// getNewOrder1 under the tensor product reordering procedure, this function
	// is able to shuffle the qubit that this Calculation is concerning right to the end
	// of the tensor product stack
	std::vector<SVPair> getNewOrder1(std::vector<SVPair> oldOrder) {
		std::vector<SVPair> newOrder;
		for (int i = 0; i < oldOrder.size(); i++) {
			if (!locations_[0].areEqual(oldOrder[i])) {
				newOrder.push_back(oldOrder[i]);
			}
		}
		newOrder.push_back(locations_[0]);
		return newOrder;
	}

	// getNewOrder2 under the tensor product reordering procedure, this function
	// is able to shuffle the two qubits that this Calculation is concerning right to the end
	// of the tensor product stack
	std::vector<SVPair> getNewOrder2(std::vector<SVPair> oldOrder) {
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
	// getNewOrder is important for the statevector computation mode. When performing the
	// matrix multiplication we are using a specialised tensor product (for efficiency) which
	// relies on the two concerned qubits to be pushed to the back of the tensor product stack.
	std::vector<SVPair> getNewOrder(std::vector<SVPair> oldOrder) {
		if (locations_.size() != 2 && locations_.size() != 1) {
			return oldOrder;
		}
		if (locations_.size() == 2) {
			return getNewOrder2(oldOrder);
		}
		return getNewOrder1(oldOrder);
	}

	std::vector<Qubit*> getQubits() {
		return qubitValues_;
	}
};

// MeasureCommand provides a simple datastructure to track measurement commands from
// the user during parsing.
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

// StateVector is a core component of the quantum computation stack.
// In Fast compute mode, Statevector is used to store the overall results of the computation
// In Statevector computer mode, the Statevector is used both in the input and output of the computation
class StateVector {
private:
	// positions_ stores the current locations of different Quantum register and position pairs (each defining a qubit)
	// these locations are relevant to the order in which these qubits were multiplied in the tensor product used
	// to generate the StateVector
	std::vector<SVPair> positions_;
	// state_ is the statevector in full tensorproduct form, for a system which uses n qubits the state_variable 
	// will be 2^n long
	std::vector<std::complex<double>> state_;
	// For Fast computation mode, the qubitMap_ provides access to the actual qubit values stored in the Qubit datastructure
	std::map<std::string, std::vector<Qubit*>>* qubitMap_;
	// reordered_ is a temporary state vector used during computation to represent the temporary reordering
	// of the state vector for the tail computation
	StateVector* reordered_;
	bool isReorder = false;

	// inverseTail provides the inverse of the tail function, this allows us to calculate (given the position of
	// the qubit in the tensor product and the location in the statevector) which component of the qubit state (0th or 1th component)
	// we need to process on.
	int inverseTail(int nTotal, int indexInPositions, int locationInStateVec) {
		int j = std::pow(2, (nTotal - indexInPositions));
		if ((locationInStateVec % j) < (j / 2)) {
			return 0;
		}
		else {
			return 1;
		}
	}

	// tail provides a function (using inverseTail) to calculate whether we need the 0th or 1th component
	// of a particular qubit.
	bool tail(int nTotal, int indexInPositions, int locationInStateVec, int index) {
		return inverseTail(nTotal, indexInPositions, locationInStateVec) == index;
	}

	// used in Fast computation mode to calculate which values in a statevector is affected by a particular
	// calculation result.
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

	// calculateNewVals is used in fast computation mode for keeping track of qubit values changing compensating
	// in the state vector.
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

	// resolvePosition calculates which position in the statevector is addressed by the values given
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

	// Used in initialisation of StateVector, tensorProduct produces the default statevector which is populated by
	// calculation and returned at the end.
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

	// Will only be called during reordering, provides same function as standed tensorProduct function
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

	// modifyState used in fast computation mode to modify the statevector to try and preseve entanglement
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

	// directModify allows statevector computation mode to modify the entire statevector
	void directModify(int index, std::complex<double> value) {
		if (index >= state_.size()) {
			return;
		}
		state_[index] = value;
	}
	void directModify(std::vector<std::complex<double>> values) {
		if (values.size() != state_.size()) {
			return;
		}
		state_ = values;
	}

	// quickRefresh used in fast computation mode to recalculate the statevector values.
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

	// reorder allows us to reorder the statevector and returns this temporary vector. This 
	// vector is used in compuitation and the reconciled with original tensor product later on.
	StateVector* reorder(std::vector<SVPair> newOrder) {		
		reordered_->tensorProduct(newOrder, positions_, state_);
		return reordered_;
	}

	// reconcile accepts the temporary statevector and reorders it into the orginal order
	// and modifies the appropriate order.
	void reconcile(StateVector* reordered) {
		int n = positions_.size();
		int dimStateVec = std::pow(2, n);
		state_.resize(dimStateVec);

		for (int i = 0; i < dimStateVec; i++) {
			std::vector<int> newSchemeVals;
			for (int j = 0; j < n; j++) {
				newSchemeVals.push_back(inverseTail(n, j, i));
			}
			std::vector<int> oldSchemeVals = mapToOldScheme(newSchemeVals, positions_, reordered->getOrder());
			state_[i] = reordered->getState()[resolvePosition(oldSchemeVals)];
		}
	}

	int getN() {
		return positions_.size();
	}

	std::vector<SVPair> getOrder() {
		return positions_;
	}

	std::complex<double> getSVValue(int i) {
		return state_[i];
	}

	~StateVector() {
		if (!isReorder) {
			delete reordered_;
		}
	}
};