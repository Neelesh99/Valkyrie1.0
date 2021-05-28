# This is a sample Python script.
from ValkyrieFunctions import *
from qiskit import *
from qiskit import Aer
import cirq
import time

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


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




# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    for i in range(101):
        baselineCirq()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
