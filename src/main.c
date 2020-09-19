#include<stdio.h>
#include"num.h"

int main() {
	int a[100];
	newNum(a, 3);
	printNum(a);
	multiply(a, -7);
	printNum(a);
	divide(a, 27);
	printNum(a);
	multiply(a, -7);
	printNum(a);
	divide(a, 78);
	printNum(a);
	multiply(a, 32);
	printNum(a);
	return 0;
}
