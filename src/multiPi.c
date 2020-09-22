#include<stdio.h>
#include"num.h"

int* getPibyBBP(int pi[], int precision){
    newNum(pi, 0);
    int precisionDelta[100];
    newNum(precisionDelta, 4);
    shiftRight(precisionDelta, precision + 1);
    for(int k = 0; k < 100; k++) {
        int a[100];divideInt(newNum(a, 4), (8*k +1));
        int b[100];divideInt(newNum(b, 2), (8*k +4));
        int c[100];divideInt(newNum(c, 1), (8*k +5));
        int d[100];divideInt(newNum(d, 1), (8*k +6));
        int delta1[100];addNum(addNum(b, c, delta1), d, delta1);
        int delta[100]; addNum(a, multiInt(delta1, -1), delta);
        for(int i = 0; i<k; i++){
            divideInt(delta, 16);
        }
        addNum(pi, delta, pi);
        printNum(pi);
        if(compareAbs(delta, precisionDelta) == -1){
            break;
        }
    }

    return pi;
}


int* getPibyLeibniz(int pi[], int precision) {
    newNum(pi, 0);
    /*initialize a small number to be precisionDelta*/
    int precisionDelta[100];
    newNum(precisionDelta, 4);
    shiftRight(precisionDelta, precision + 1);
    printNum(precisionDelta);

    for (int k = 0; 1 ; k++) {
        int delta[100];
        divideInt(newNum(delta, 1), 2 * k + 1);
        if (k % 2 == 1) {
            delta[0] = -1;
        }
        multiInt(delta, 4);
        addNum(pi, delta, pi);
        //printNum(pi);
        if(compareAbs(delta, precisionDelta) == -1){
            printNum(delta);
            printNum(precisionDelta);
            printf(" p = %d\n", precision + 1);
            break;
        }
    }

    return pi;
}