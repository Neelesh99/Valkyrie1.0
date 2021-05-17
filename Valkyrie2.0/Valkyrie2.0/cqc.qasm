OPENQASM 2.0;
qreg q[3];
creg c[3];
h q[2];
cx q[0], q[1];
measure q -> c;