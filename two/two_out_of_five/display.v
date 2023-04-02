module display (
	v,
	a, b, c, d, e,
	A, B, C, D, E, F, G
);

	input  v, a, b, c, d, e;
	output A, B, C, D, E, F, G;
	
	
	
	wire vn;
	
	wire an, bn, cn, dn, en;
	wire zero, one, two, three, four, five, six, seven, nine;
	
	// not
	not(vn, v);
	
	not(an, a);
	not(bn, b);
	not(cn, c);
	not(dn, d);
	not(en, e);
	
	and(zero, an, bn, c, d, en);
	and(one, a, bn, cn, dn, e);
	and(two, an, b, cn, dn, e);
	and(three, a, b, cn, dn, en);
	and(four, an, bn, c, dn, e);
	and(five, a, bn, c, dn, en);
	and(six, an, b, c, dn, en);
	and(seven, an, bn, cn, d, e);
	and(nine, an, b, cn, d, en);
	
	// A
	or(A, one, four);
	
	// B
	or(B, five, six, vn);
	
	// C
	or(C, two, vn);
	
	// D
	or(D, one, four, seven);
	
	// E
	or(E, one, three, four, five, seven, nine);
	
	// F
	or(F, one, two, three, seven);
	
	// G
	or(G, zero, one, seven);
	
	
endmodule 