#include "AbstractDevice.h"
#include "cuda_runtime.h"

class GPUQubitFactory : public AbstractQubitFactory {
private:
	DeviceType type_;
	std::vector<Qubit*> qubits_;
public:
	GPUQubitFactory() {
		type_ = CPU_;
	}
	Qubit* generateQubit();
	~GPUQubitFactory();
};

class GPUGateFactory : public AbstractGateFactory {
private:
	DeviceType type_;
	std::vector<Gate*> gates_;
public:
	GPUGateFactory() {
		type_ = CPU_;
	}
	Gate* generateGate(GateRequest request);
	~GPUGateFactory();
};

class GPUQuantumCircuit : public AbstractQuantumCircuit {
private:
	DeviceType type_;
	bool done_;
	std::map<std::string, std::vector<Qubit*>> qubitMap_;
	std::vector<std::vector<Calculation>> calculations_;
	GPUGateFactory* gateFactory_;
	int calcCounter = 0;
	std::vector<SVPair> zipSVPairs(std::vector<std::string> names, std::vector<int> locs);
	StateVector* sv_;
public:
	GPUQuantumCircuit(GPUGateFactory* gateFactory) {
		gateFactory_ = gateFactory;
		type_ = CPU_;
		done_ = false;
	}
	void loadQubitMap(std::map<std::string, std::vector<Qubit*>> qubitMap);
	void loadBlock(ConcurrentBlock block);
	std::vector<Calculation> getNextCalculation();
	std::map<std::string, std::vector<Qubit*>> returnResults();
	StateVector* getStateVector();
	bool checkComplete();
	~GPUQuantumCircuit() {
		delete sv_;
	}
};

class GPUQuantumProcessor : public AbstractQuantumProcessor {
private:
	DeviceType type_;
	AbstractQuantumCircuit* circuit_;
public:
	GPUQuantumProcessor() {
		type_ = CPU_;
	}
	void loadCircuit(AbstractQuantumCircuit* circuit);
	void calculate();
	std::map<std::string, std::vector<Qubit*>> qubitMapfetchQubitValues();
};

class GPUDevice : public AbstractDevice {
private:
	DeviceType type_;
	std::map<std::string, std::vector<Qubit*>> registerMap;
	GPUQubitFactory* qubitFactory;
	GPUGateFactory* gateFactory;
	GPUQuantumCircuit* quantumCircuit;
	GPUQuantumProcessor* quantumProcessor;
public:
	GPUDevice() {
		type_ = CPU_;
		qubitFactory = new GPUQubitFactory();
		gateFactory = new GPUGateFactory();
		quantumCircuit = new GPUQuantumCircuit(gateFactory);
		quantumProcessor = new GPUQuantumProcessor();
	}
	void loadRegister(Register registerx);
	void transferQubitMap();
	void loadConcurrentBlock(ConcurrentBlock block);
	void runSimulation();
	void run(std::vector<Register> registers, std::vector<ConcurrentBlock> blocks);
	std::map<std::string, std::vector<Qubit*>> revealQuantumState();
	void prettyPrintQubitStates(std::map<std::string, std::vector<Qubit*>> qubits) {
		for (std::map<std::string, std::vector<Qubit*>>::iterator it = qubits.begin(); it != qubits.end(); ++it) {
			std::cout << "Register: " << it->first << std::endl;
			std::vector<Qubit*> regQubits = it->second;
			for (int i = 0; i < regQubits.size(); i++) {
				std::cout << "Location [" << i << "]: " << regQubits[i]->fetch(0)->real() << "+" << regQubits[i]->fetch(0)->imag() << "i" << " ||| " << regQubits[i]->fetch(1)->real() << "+" << regQubits[i]->fetch(1)->imag() << "i" << std::endl;
			}
		}
	}
	StateVector* getStateVector() {
		return quantumCircuit->getStateVector();
	}
	~GPUDevice() {
		delete qubitFactory;
		delete gateFactory;
		delete quantumCircuit;
		delete quantumProcessor;
	}
};
