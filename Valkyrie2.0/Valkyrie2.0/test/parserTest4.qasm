OPENQASM 2.0;
qreg q[3];
creg c[3];
h q[0];
cx q[0], q[1];
measure q[0] -> c[0];