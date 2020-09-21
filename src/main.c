#include<stdio.h>
#include"num.h"
#include"multiPi.h"

int main() {
	int pi[100];
	newNum(pi, 3);
	printNum(pi);
	divide(pi, 7);
	printNum(pi);
	return 0;
}
