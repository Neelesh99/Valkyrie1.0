# This is a sample Python script.
from ValkyrieFunctions import *
from qiskit import *
from qiskit import Aer
import time

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    circ = QuantumCircuit()
    qr = QuantumRegister(10, "q")
    circ.add_register(qr)
    circ.h(qr[0])
    circ.h(qr[1])
    circ.h(qr[7])
    circ.h(qr[6])
    circ.cx(qr[0], qr[4])
    circ.cx(qr[1], qr[2])
    circ.cx(qr[7], qr[8])
    circ.measure_all()
    # generateOutputFile(circ)
    # scrubqeLib("temp.qasm")
    # runValkyrie()
    start_time = time.time()
    simulator = Aer.get_backend("qasm_simulator")
    job = execute(circ, simulator)
    result = job.result()
    print("--- %s seconds ---" % (time.time() - start_time))

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
