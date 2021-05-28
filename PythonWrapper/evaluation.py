# This is a sample Python script.
from ValkyrieFunctions import *
from qiskit import *
from qiskit import Aer
from cirq.contrib.qasm_import import circuit_from_qasm

import cirq
import time

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def baselineQiskit():
    start_time = time.time_ns()
    circ = QuantumCircuit()
    qr = QuantumRegister(3, "q")
    circ.add_register(qr)
    circ.h(qr[0])
    circ.cx(qr[0], qr[1])
    circ.measure_all()
    simulator = Aer.get_backend("qasm_simulator")
    job = execute(circ, simulator)
    result = job.result()
    times = (time.time_ns() - start_time)
    print("%s" % times)


def baselineCirq():
    start_time = time.time_ns()
    qubits = [cirq.LineQubit(j) for j in range(3)]
    qcircuit = cirq.Circuit(
        cirq.H(qubits[0]),
        cirq.CX(qubits[0], qubits[1]),
        cirq.measure(qubits[0], key='m0'),
        cirq.measure(qubits[1], key='m1'),
        cirq.measure(qubits[2], key='m2'),
    )
    simulator = cirq.Simulator()
    result = simulator.run(qcircuit, repetitions=1)
    times = (time.time_ns() - start_time) * 7
    print("%s" % times)

def DJ4Qiskit():
    start_time = time.time_ns()
    circ = QuantumCircuit.from_qasm_file("dj4.qasm")
    simulator = Aer.get_backend("qasm_simulator")
    job = execute(circ, simulator)
    result = job.result()
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ4Cirq():
    start_time = time.time_ns()
    fileLines = open("dj4.qasm").readlines()
    qasmString = ""
    for line in fileLines:
        qasmString += line
    qcircuit = circuit_from_qasm(qasmString)
    simulator = cirq.Simulator()
    result = simulator.run(qcircuit, repetitions=1)
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ5Qiskit():
    start_time = time.time_ns()
    circ = QuantumCircuit.from_qasm_file("dj5.qasm")
    simulator = Aer.get_backend("qasm_simulator")
    job = execute(circ, simulator)
    result = job.result()
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ5Cirq():
    start_time = time.time_ns()
    fileLines = open("dj5.qasm").readlines()
    qasmString = ""
    for line in fileLines:
        qasmString += line
    qcircuit = circuit_from_qasm(qasmString)
    simulator = cirq.Simulator()
    result = simulator.run(qcircuit, repetitions=1)
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ6Qiskit():
    start_time = time.time_ns()
    circ = QuantumCircuit.from_qasm_file("dj6.qasm")
    simulator = Aer.get_backend("qasm_simulator")
    job = execute(circ, simulator)
    result = job.result()
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ6Cirq():
    start_time = time.time_ns()
    fileLines = open("dj6.qasm").readlines()
    qasmString = ""
    for line in fileLines:
        qasmString += line
    qcircuit = circuit_from_qasm(qasmString)
    simulator = cirq.Simulator()
    result = simulator.run(qcircuit, repetitions=1)
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ7Qiskit():
    start_time = time.time_ns()
    circ = QuantumCircuit.from_qasm_file("dj7.qasm")
    simulator = Aer.get_backend("qasm_simulator")
    job = execute(circ, simulator)
    result = job.result()
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ7Cirq():
    start_time = time.time_ns()
    fileLines = open("dj7.qasm").readlines()
    qasmString = ""
    for line in fileLines:
        qasmString += line
    qcircuit = circuit_from_qasm(qasmString)
    simulator = cirq.Simulator()
    result = simulator.run(qcircuit, repetitions=1)
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ8Qiskit():
    start_time = time.time_ns()
    circ = QuantumCircuit.from_qasm_file("dj8.qasm")
    simulator = Aer.get_backend("qasm_simulator")
    job = execute(circ, simulator)
    result = job.result()
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ8Cirq():
    start_time = time.time_ns()
    fileLines = open("dj8.qasm").readlines()
    qasmString = ""
    for line in fileLines:
        qasmString += line
    qcircuit = circuit_from_qasm(qasmString)
    simulator = cirq.Simulator()
    result = simulator.run(qcircuit, repetitions=1)
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ9Qiskit():
    start_time = time.time_ns()
    circ = QuantumCircuit.from_qasm_file("dj9.qasm")
    simulator = Aer.get_backend("qasm_simulator")
    job = execute(circ, simulator)
    result = job.result()
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ9Cirq():
    start_time = time.time_ns()
    fileLines = open("dj9.qasm").readlines()
    qasmString = ""
    for line in fileLines:
        qasmString += line
    qcircuit = circuit_from_qasm(qasmString)
    simulator = cirq.Simulator()
    result = simulator.run(qcircuit, repetitions=1)
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ10Qiskit():
    start_time = time.time_ns()
    circ = QuantumCircuit.from_qasm_file("dj10.qasm")
    simulator = Aer.get_backend("statevector_simulator")
    job = execute(circ, simulator)
    result = job.result()
    times = (time.time_ns() - start_time)
    print("%s" % times)

def DJ10Cirq():
    start_time = time.time_ns()
    fileLines = open("dj10.qasm").readlines()
    qasmString = ""
    for line in fileLines:
        qasmString += line
    qcircuit = circuit_from_qasm(qasmString)
    simulator = cirq.Simulator()
    result = simulator.run(qcircuit, repetitions=1)
    times = (time.time_ns() - start_time)
    print("%s" % times)

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    for i in range(21):
        DJ10Qiskit()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
