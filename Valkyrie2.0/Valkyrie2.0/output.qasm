OPENQASM 2.0;
qreg q[3];
h q[0];
cx q[0],q[1];
cx q[0],q[2];
U (0,0,0) q[0];
