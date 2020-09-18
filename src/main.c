#include<stdio.h>
#include"num.h"

double getPibyBBP(){
	double pi = 0.0;
	double deno = 1.0;
	
	for(int k = 0; k < 20; k++){
		pi += (4.0/(8*k +1.0) - 2.0/(8*k +4.0) - 1.0/(8*k +5.0) - 1.0/(8*k +6.0)) * deno;
		deno = deno / 16.0;
		printf("pi(%d):\t%.50f\n", k, pi);
	}
	return pi;
}

int main() {
	int a[100];
	newNum(3, a);
	printNum(a);
	multiply(7, a);
	printNum(a);
	return 0;
}
