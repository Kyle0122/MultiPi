#include <stdio.h>
#include "num.h"
#include "multiPi.h"

int main() {
	int pi[100];
	newNum(pi, 0);

	//getPibyBBP(pi, 100);
	getPibyLeibniz(pi, 5);

	/*int b[100];
	newNum(b, 8);
	divideInt(b, 3);

	int c[100];
	newNum(c, 4);
	multiNum(b, c, pi);*/
	
	printNum(pi);
	return 0;
}
