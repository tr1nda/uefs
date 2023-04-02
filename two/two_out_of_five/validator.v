module validator (
	a, b, c, d, e,
	v
);

	input  a, b, c, d, e;
	output v;
	
	wire an, bn, cn, dn, en;
	wire o1, o2, o3, o4, o5, o6, o7, o8, o9, o10;
	
	not(an, a);
	not(bn, b);
	not(cn, c);
	not(dn, d);
	not(en, e);
	
	// 1
	and(o1, an, bn, cn, d, e);
	
	// 2
	and(o2, an, bn, c, d, en);
	
	// 3
	and(o3, an, bn, c, dn, e);
	
	// 4
	and(o4, an, b, cn, dn, e);
	
	// 5
	and(o5, an, b, cn, d, en);
	
	// 6
	and(o6, an, b, c, dn, en);
	
	// 7
	and(o7, a, b, cn, dn, en);
	
	// 8
	and(o8, a, bn, cn, dn, e);
	
	// 9
	and(o9, a, bn, cn, d, en);
	
	// 10
	and(o10, a, bn, c, dn, en);
	
	// end
	or(v, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10);
endmodule