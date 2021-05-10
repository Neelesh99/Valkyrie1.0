#pragma once
#include <vector>
#include <string>
#include <complex>

enum DeviceType {
	CPU_,
	GPU_
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
public:
	ClassicalRegister(std::string identifier, int width) {
		identifier_ = identifier;
		width_ = width;
	}
	std::string getIdentifier() {
		return identifier_;
	}
	int getWidth() {
		return width_;
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
	CUSTOM
};

class GateRequest {
private:
	GateRequestType gateType_;
	std::vector<std::string> registerIdentifiers_;
	std::vector<int> locations_;
	std::vector<double> parameters_;
public:
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
public:
	Calculation(Gate* gate, std::vector<Qubit*> qubitVals) {
		gate_ = gate;
		qubitValues_ = qubitVals;
	}
	Gate* getGate() {
		return gate_;
	}
	Qubit* getQubit(int i) {
		return qubitValues_[i];
	}

	std::vector<Qubit*> getQubits() {
		return qubitValues_;
	}
};


