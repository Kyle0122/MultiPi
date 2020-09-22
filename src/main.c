#include <stdio.h>
#include "num.h"
#include "multiPi.h"

int main() {
	int pi[100];
	newNum(pi, 0);

	getPibyBBP(pi, 9);
	//getPibyLeibniz(pi, 5);
	//getPibyEuler(pi, 6);
/*
	int b[100];
	newNum(b, 2);
	sqrtNum(b);

	int c[100];
	newNum(c, 1);
	divideInt(c, 888);
	divideNum(b, c, pi);*/
	
	printNum(pi);
	return 0;
}
