#include"num.h"
#include<stdio.h>

//initialize the number array with a integer
//N[0] is only the sign of the number(-1 for minus and +1 for plus)
//N[1] is the integer part of the number,
//and the rest of the array is the decimal part
int* newNum(int N[], int a) {
    if(a < 0) {
        N[0] = -1;
        N[1] = -a;
    }else {
        N[0] = 1;
        N[1] = a;
    }
    for(int i = 2; i < 100; i++){
        N[i] = 0;
    }
    return N;
}

//N = N * b
void multiply(int N[], int b) {
    if(b < 0) {
        b = -b;
        N[0] = -N[0];
    }
    if(b > SCALE) {
        printf("too big to multiply\n");
        return;
    }
    int remain = 0;
    for(int i = 99; i >= 1; i--) {
        N[i] = N[i] * b;
        N[i] = N[i] + remain;
        if(i != 1){
            remain = N[i] / SCALE;
            N[i] = N[i] % SCALE;
        }
    }
}

//N = N / b
void divide(int N[], int b) {
    if(b < 0) {
        b = -b;
        N[0] = -N[0];
    }
    if(b > SCALE){
        printf("too big to divide\n");
        return;
    }
    int remain = 0;
    for(int i = 1; i < 100; i++){
        remain = (N[i] % b) * SCALE;
        N[i] = N[i] / b;
        if(i != 99) {
            N[i+1] = N[i+1] + remain;
        }else if(remain > SCALE/2){
            N[i] ++;
        }
        
    }
}

//c = a + b, return pointer to c
int* add(int a[], int b[], int c[]) {
    if(a[0] > 0 && b[0] > 0) {
        c[0] = 1;
    }else if(a[0] < 0 && b[0] < 0) {
        c[0] = -1;
    }else if(a[0] > 0 && b[0] < 0) {
        b[0] = 1;
        subtract(a, b, c);
        b[0] = -1;
        return c;
    }else if(a[0] < 0 && b[0] > 0) {
        a[0] = 1;
        subtract(b, a, c);
        a[0] = -1;
        return c;
    }
    int remain = 0;
    for(int i = 99; i >= 1; i--) {
        c[i] = a[i] + b[i] + remain;
        remain = c[i] / SCALE;
        c[i] = c[i] % SCALE;
    }
    return c;
}

//c = a - b, return pointer to c
int* subtract(int a[], int b[], int c[]){
    if(a[0] > 0 && b[0] < 0) {
        b[0] = 1;
        add(a, b, c);
        b[0] = -1;
        return c;
    }else if(a[0] < 0 && b[0] > 0) {
        b[0] = -1;
        add(a, b, c);
        b[0] = 1;
        return c;
    }else if(a[0] > 0 && b[0] > 0) {
        return c;
    }else if(a[0] < 0 && b[0] < 0) {
        return c;
    }
    return c;
}

//return 1 if a>b, -1 if a<b, 0 if a==b
int compare(int a[], int b[]) {
    for(int i = 0; i < 100; i++){
        if(a[i] > b[i]){
            return 1;
        }else if(a[i] < b[i]){
            return -1;
        }
    }
    return 0;
}

void printNum(int N[]) {
    if(N[0] < 0){
        printf("-");
    }
    printf("%d.", N[1]);
    for(int i = 2; N[i] != 0 && i < 100; i++){

        printf("%05d ", N[i]);
    };
    printf("\n");
}