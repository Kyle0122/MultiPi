#include <stdio.h>
#include "num.h"
#include "multiPi.h"

int main() {
	int pi[100];
	newNum(pi, 8);
	divideInt(pi, 3);

	//getPibyBBP(pi, 100);
	//getPibyLeibniz(pi, 3);

	int b[100];
	newNum(b, 8);

	int c[100];
	newNum(c, 0);
	multiNum(pi, b, c);
	
	printNum(c);
	return 0;
}
