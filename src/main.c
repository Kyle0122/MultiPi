#include <stdio.h>
#include "num.h"
#include "multiPi.h"

int main() {
	int pi[ARRAYLENGTH];
	newNum(pi, 0);

	int n;
	n = getPibyBBP(pi, 3*(ARRAYLENGTH-4));
	printf("n = %d\t", n);printNum(pi, 8);
	//n = getPibyLeibniz(pi, 6);
	//printf("n = %d\t", n);printNum(pi);
	//n = getPibyEuler(pi, 6);
	//printf("n = %d\t", n);printNum(pi);
	//getPibylaman(pi, 30);
	//printf("n = 10\t");printNum(pi);
	
	return 0;
}
