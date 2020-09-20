#include<stdio.h>
#include"num.h"

void getPibyBBP(int pi[]){
	newNum(pi, 0);
	for(int k = 0; k < 100; k++){
        int a[100];divide(newNum(a, 4), (8*k +1));
        int b[100];divide(newNum(b, 2), (8*k +4));
        int c[100];divide(newNum(c, 1), (8*k +5));
        int d[100];divide(newNum(d, 1), (8*k +6));
		int delta1[100];add(add(b, c, delta1), d, delta1);
        int delta[100]; add(a, multiply(delta1, -1), delta); 
        for(int i = 0; i<k; i++){
            divide(delta, 16);
        }
        add(pi, delta, pi);
        printNum(pi);
	}
}