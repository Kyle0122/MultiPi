#include"num.h"
#include<stdio.h>

//initialize the number array with a integer
//N[0] is the sign of the number(-1 for minus and +1 for plus)
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
    for(int i = 2; i < ARRAYLENGTH; i++){
        N[i] = 0;
    }
    return N;
}

//N = N * b
int* multiply(int N[], int b) {
    if(b < 0) {
        b = -b;
        N[0] = -N[0];
    }
    if(b > SCALE) {
        printf("too big to multiply\n");
        return N;
    }
    int remain = 0;
    for(int i = ARRAYLENGTH-1; i >= 1; i--) {
        N[i] = N[i] * b;
        N[i] = N[i] + remain;
        if(i != 1){
            remain = N[i] / SCALE;
            N[i] = N[i] % SCALE;
        }
    }
    return N;
}

//N = N / b, b should be  less than or equal to SCALE, which is 100000
int* divide(int N[], int b) {
    if(b < 0) {
        b = -b;
        N[0] = -N[0];
    }
    if(b > SCALE){
        printf("too big to divide\n");
        return N;
    }
    int remain = 0;
    for(int i = 1; i < ARRAYLENGTH; i++){
        remain = (N[i] % b) * SCALE;
        N[i] = N[i] / b;
        if(i != ARRAYLENGTH-1) {
            N[i+1] = N[i+1] + remain;
        }else if(remain > SCALE/2){
            N[i] ++;
        }
    }
    return N;
}

//c = a + b, return pointer to c, note that don't let b==c
int* add(int a[], int b[], int c[]) {
    //variable ab represents the relation between abs(a) and abs(b)
    int ab = compareAbs(a, b);
    int *biggerArray;
    int *smallerArray;
    //decide which number has bigger absolute value:
    if(ab >= 0){
        biggerArray = a;
        smallerArray = b;
    }else if(ab < 0) {
        biggerArray = b;
        smallerArray = a;
    }

    //if a == -b, return 0;
    if(a[0]*b[0] == -1 && ab == 0){
        return newNum(c, 0);
    }

    //variable doAdd ==1 means add two number, ==-1 means subtract two number
    int doAdd = 0;
    if(a[0] > 0 && b[0] > 0) {
        c[0] = 1;
        doAdd = 1;
    }else if(a[0] < 0 && b[0] < 0) {
        c[0] = -1;
        doAdd = 1;
    }else if(a[0] > 0 && b[0] < 0) {
        doAdd = -1;
        if(ab > 0){
            c[0] = 1;
        }else {
            c[0] = -1;
        }
    }else if(a[0] < 0 && b[0] > 0) {
        doAdd = -1;
        if(ab > 0){
            c[0] = -1;
        }else {
            c[0] = 1;
        }
    }

    if(doAdd == 1) {
        int remain = 0;
        for(int i = ARRAYLENGTH-1; i >= 1; i--) {
            c[i] = a[i] + b[i] + remain;
            remain = c[i] / SCALE;
            c[i] = c[i] % SCALE;
        }
    }else if(doAdd == -1){
        int remain = 0;
        for(int i = ARRAYLENGTH-1; i >= 1; i--) {
            c[i] = biggerArray[i] - smallerArray[i] + remain;
            if(c[i] < 0 && i != 1){
                c[i] = c[i] + SCALE;
                remain = -1;
            }else {
                remain = 0;
            }
        }
    }
    return c;
}

//return 1 if a>b, -1 if a<b, 0 if a==b
int compareAbs(int a[], int b[]) {
    for(int i = 0; i < ARRAYLENGTH; i++){
        if(a[i] > b[i]){
            return 1;
        }else if(a[i] < b[i]){
            return -1;
        }
    }
    return 0;
}

//copy a to b, return pointer of b
int* copyNum(int a[], int b[]){
    for(int i = 0; i < ARRAYLENGTH; i++){
        b[i] = a[i];
    }
    return b;
}

void printNum(int N[]) {
    if(N[0] < 0){
        printf("-");
    }
    printf("%d.", N[1]);
    //the last number in the array is omitted sence it is usually unprecice
    for(int i = 2; N[i] != 0 && i < ARRAYLENGTH-1; i++){
        printf("%05d ", N[i]);
    };
    printf("\n");
}