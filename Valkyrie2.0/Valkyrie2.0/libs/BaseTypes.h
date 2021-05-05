#pragma once
#include <vector>
#include <string>

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
	classical_
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
};



enum GateRequestType {
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
public:
	GateRequest(GateRequestType type) {
		gateType_ = type;
	}
	void addressQubit(std::string registerID, int location) {
		registerIdentifiers_.push_back(registerID);
		locations_.push_back(location);
	}
	int getGateDim() {
		return registerIdentifiers_.size() + locations_.size() - 1;
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
