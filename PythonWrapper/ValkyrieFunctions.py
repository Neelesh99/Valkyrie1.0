from qiskit import *
import os
import subprocess
def printHello():
    print("Hello")
def generateOutputFile(circ : QuantumCircuit):
    circ.qasm(True, "temp.qasm")

def scrubqeLib(filename):
     original = open(filename, "r")
     listOfLines = original.readlines()
     original.close()
     finalLines = listOfLines.pop(1)
     finalFile = open("output.qasm", "w")
     for element in listOfLines:
         finalFile.write(element)
     finalFile.close()

def runValkyrie():
    process = subprocess.run(['Debug\\Valkyrie2.0.exe', '-c', '-o', 'output.qasm', '-sv'])
