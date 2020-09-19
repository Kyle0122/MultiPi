#include<stdio.h>
#include"num.h"

void getPibyBBP(int pi[]){
	int deno = 1;
	newNum(pi, 0);
	for(int k = 0; k < 8; k++){
        int a[100];divide(newNum(a, 4), (8*k +1));
        int b[100];divide(newNum(b, 2), (8*k +4));
        int c[100];divide(newNum(c, 1), (8*k +5));
        int d[100];divide(newNum(d, 1), (8*k +6));
		int delta1[100]; add(b, c, delta1);
        int delta2[100]; add(delta1, d, delta2);
        int delta[100]; add(a, multiply(delta2, -1), delta);
        divide(delta, deno);
        
		add(pi, delta, pi);
        printNum(pi);
        deno = deno * 16;
	}
}