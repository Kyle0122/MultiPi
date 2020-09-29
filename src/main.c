#include <stdio.h>
#include <stdlib.h>
#include "num.h"
#include "multiPi.h"

int main(int argc, char *argv[]) {
	int pi[ARRAYLENGTH];
	newNum(pi, 0);
	int n = 0;

	int precision = atoi(argv[2]);
	if(argv[1][0] == 'L' && argv[1][1] == 'e'){
		printf("calc pi by Leibniz, precision = %d:\n", precision);
		n = getPibyLeibniz(pi, precision);
		printNum(pi, precision);
		printf("n = %d, Average speed: %.9f\n", n, (double)precision/n);
	}else if(argv[1][0] == 'E' && argv[1][1] == 'u'){
		printf("calc pi by Euler, precision = %d:\n", precision);
		n = getPibyEuler(pi, precision);
		printNum(pi, precision);
		printf("n = %d, Average speed: %.9f\n", n, (double)precision/n);
	}else if(argv[1][0] == 'L' && argv[1][1] == 'a'){
		printf("calc pi by Laman, precision = %d:\n", precision);
		n = getPibyLaman(pi, precision);
		printNum(pi, precision);
		printf("n = %d, Average speed: %.9f\n", n, (double)precision/n);
	}else if(argv[1][0] == 'B' && argv[1][1] == 'B'){
		printf("calc pi by BBP, precision = %d:\n", precision);
		n = getPibyBBP(pi, precision);
		printNum(pi, precision);
		printf("n = %d, Average speed: %.9f\n", n, (double)precision/n);
	}else {
		printf("calc speed for each method:\n");
		printf("Leibniz:\n");
		for(int i = 1; i <= 6; i++){
			n = getPibyBBP(pi, i);
			printf("precision = %d, n = %d\n", i, n);
		}
		printf("n = %d, Average speed: %.9f\n", n, (double)precision/n);
	}
	
	return 0;
}
