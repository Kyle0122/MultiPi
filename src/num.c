#include"num.h"
#include<stdio.h>

//initialize the number array with a integer
//N[0] is the integer part of the number,
//and the rest of the array is the decimal part
int newNum(int a, int N[]) {
    N[0] = a;
    for(int i = 1; i < 100; i++){
        N[i] = 0;
    }
    return 0;
}

void multiply(int N[], int b) {
    if(b > SCALE){
        printf("too big to multiply\n");
        return;
    }
    for(int i = 99; i >= 0; i--){
        N[i] = N[i] * b;
        if(N[i] > SCALE && i != 0){
            N[i-1] += N[i] / SCALE;
            N[i] = N[i] % SCALE;
        }
    }
}

void divide(int N[], int b) {
    if(b > SCALE){
        printf("too big to divide\n");
        return;
    }
    int remain = 0;
    for(int i = 0; i < 99; i++){
        remain = (N[i] % b) * SCALE;
        N[i] = N[i] / b;
        N[i+1] = N[i+1] + remain;
    }
    N[99] = N[99] / b;
}

void printNum(int N[]) {
    printf("%d.", N[0]);
    for(int i = 1; N[i] != 0 && i < 100; i++){
        printf("%d ", N[i]);
    };
    printf("\n");
}