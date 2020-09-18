#include"num.h"
#include<stdio.h>

int newNum(double a, struct num *N) {
    N->giga = (int)a;
    N->nanos[0] = (int)((a - N->giga) * 1000000000);
    return 0;
}

void printNum(struct num *N) {
    printf("%d.%d\n", N->giga, N->nanos[0]);
}