#include<stdio.h>
#include"num.h"
#include"multiPi.h"

int main() {
	int a[100];newNum(a, 3);
	printNum(a);
	multiply(a, 7);
	printNum(a);
	divide(a, 27);
	printNum(a);
	
	int b[100];newNum(b, 21);
	divide(b, 27);
	divide(b, 1000);
	
	printNum(b);

	printf("%d \n", compare(a, b));
	/*
	subtract(b, a, c);
	printNum(c);*/
/*
	int pi[100];
	getPibyBBP(pi);
	printNum(pi);
*/
	return 0;
}
