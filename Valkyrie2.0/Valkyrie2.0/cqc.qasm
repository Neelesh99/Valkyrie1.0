OPENQASM 2.0;

gate fup(theta,phi,lambda) q {U(theta,phi,lambda) q;}
gate xB a { u3(pi,0,pi) a; }

qreg q[3];
creg c[3];
h q[2];
cx q[0], q[1];
fup(pi,0,pi) q[0];
measure q -> c;