#include <stdio.h>
#include "num.h"
#include "multiPi.h"

int main() {
	int pi[100];
	newNum(pi, 0);

	int n;
	n = getPibyBBP(pi, 18);
	printf("n = %d\t", n);printNum(pi);
	//n = getPibyLeibniz(pi, 6);
	//printf("n = %d\t", n);printNum(pi);
	//n = getPibyEuler(pi, 6);
	//printf("n = %d\t", n);printNum(pi);
	getPibylaman(pi, 1);
	printNum(pi);


/*
	int b[100];
	newNum(b, 1);

	int c[100];
	newNum(c, 25008);
	printNum(addNum(b, c, b));
	printf("%d \n", compareAbs(b, c));
	//multiInt(c, 1000000000);
	//divideNum(b, c, pi);*/
	
	return 0;
}
