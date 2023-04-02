/*
 * Hardware Description Project
 * of the discipline TEC498-TP01
 * at the Universidade Estadual
 * da Bahia - UEFS.
 */
 
module two_out_of_five (a, b, cin, s, cout);
	// gates
	input  a, b, cin;
	output s, cout;
	
	// wires
	wire w1, w2, w3;
	
	// operation
	xor u0 (w1, a, b);
	xor u1 (s, w1, cin);
	and u2 (w2, cin, w1);
	and u3 (w3, a, b);
	or  u4 (cout, w2, w3);
	
endmodule