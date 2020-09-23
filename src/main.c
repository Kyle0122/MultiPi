#include <stdio.h>
#include "num.h"
#include "multiPi.h"

int main() {
	int pi[100];
	newNum(pi, 0);

	getPibyBBP(pi, 9);
	printNum(pi);
	getPibyLeibniz(pi, 6);
	printNum(pi);
	getPibyEuler(pi, 6);
	printNum(pi);

/*
	int b[100];
	newNum(b, 2);
	sqrtNum(b);
	printNum(b);

	int c[100];
	newNum(c, 1);
	//multiInt(c, 1000000000);
	//divideNum(b, c, pi);*/
	
	return 0;
}
