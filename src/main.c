#include<stdio.h>
#include"num.h"
#include"multiPi.h"

int main() {
	int a[100];newNum(a, 3);
	multiply(a, 7);
	printNum(a);
	divide(a, 27);
	printNum(a);
	
	int b[100];newNum(b, 21);
	divide(b, 27);
	divide(b, 1000);
	printNum(b);

	int c[100];
	printNum(add(a, multiply(b, -1), c));


	int pi[100];
	getPibyBBP(pi);
	printNum(pi);

	return 0;
}
