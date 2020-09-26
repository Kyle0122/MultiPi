#include <stdio.h>
#include "num.h"
#include "multiPi.h"

int main() {
	int pi[ARRAYLENGTH];
	newNum(pi, 0);

	int n;
	n = getPibyBBP(pi, 3*(ARRAYLENGTH-4));
	printf("n = %d\t", n);printNum(pi);
	//n = getPibyLeibniz(pi, 6);
	//printf("n = %d\t", n);printNum(pi);
	//n = getPibyEuler(pi, 5);
	//printf("n = %d\t", n);printNum(pi);
	getPibylaman(pi, 10);
	printf("n = 10\t");printNum(pi);

/*
	int a[ARRAYLENGTH], b[ARRAYLENGTH], c[ARRAYLENGTH];
	newNum(a, 99 * 99 * 99 * 99);
	newNum(b, 73);
	divideInt(a, 73);
	divideInt(b, 371);
	multiInt(a, 91);
	printNum(a);
	printNum(b);
	divideNum(a, b, c);*/

	//printNum(c);
	
	return 0;
}
