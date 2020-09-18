#include"num.h"
#include<stdio.h>

//initialize the number array with a integer
int newNum(int a, int N[]) {
    N[0] = a;
    return 0;
}

void multiply(int b, int N[]){
    for(int i = 0; i < 100 && N[i] != 0; i++){
        N[i] = N[i] * b;
        if(N[i] > SCALE && i != 0){
            N[i-1] += N[i] / SCALE;
            N[i] = N[i] % SCALE;
        }
    }
}

void printNum(int N[]) {
    printf("%d.", N[0]);
    for(int i = 1; N[i] != 0; i++){
        printf("%d ", N[i]);
    };
    printf("\n");
}