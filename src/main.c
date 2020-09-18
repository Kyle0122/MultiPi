#include<stdio.h>
#include"num.h"
//pi BBP位算法
int main() {
	double pi = 0.0;
	double deno = 1.0;
	
	for(int k = 0; k < 20; k++){
		pi += (4.0/(8*k +1.0) - 2.0/(8*k +4.0) - 1.0/(8*k +5.0) - 1.0/(8*k +6.0)) * deno;
		deno = deno / 16.0;
		printf("pi(%d):\t%.50f\n", k, pi);
	}

	struct num a;
	newNum(3.149, &a);
	printNum(&a);
	return 0;
}
