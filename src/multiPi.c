#include<stdio.h>
#include"num.h"

int getPibyBBP(int pi[], int precision){
    newNum(pi, 0);
    int precisionDelta[100];
    newNum(precisionDelta, 4);
    shiftRight(precisionDelta, precision + 1);
    int k;
    for(k = 0; k < 100000; k++) {
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
        if(compareAbs(delta, precisionDelta) == -1){
            break;
        }
    }

    return k;
}

int getPibyLeibniz(int pi[], int precision) {
    newNum(pi, 0);
    /*initialize a small number to be precisionDelta*/
    int precisionDelta[100];
    newNum(precisionDelta, 4);
    shiftRight(precisionDelta, precision + 1);

    int k = 0;
    for (k = 0; k < 1000000000; k++) {
        int delta[100];
        newNum(delta, 1);
        divideInt(delta, (2 * k + 1));
        if (k % 2 == 1) {
            delta[0] = -1;
        }
        multiInt(delta, 4);
        addNum(pi, delta, pi);
        if(compareAbs(delta, precisionDelta) == -1){
            break;
        }
    }

    return k;
}

int getPibyEuler(int pi[], int precision){
    newNum(pi, 0);
    /*initialize a small number to be precisionDelta*/
    int precisionDelta[100];
    newNum(precisionDelta, 1);
    shiftRight(precisionDelta, (precision + 1) * 2 );

    int delta[100];
    int k;
    for(k = 1; k < 1000000000; k++) {
        newNum(delta, 6);
        divideInt(delta, k);
        divideInt(delta, k);
        addNum(pi, delta, pi);
        
        if(compareAbs(delta, precisionDelta) == -1){
            break;
        }
    }
    sqrtNum(pi);
    return k;
}

/*
 1   ./ 8  -- (4k)!  26390k + 1103
-- = ----- > ------- -------------
pi   99^2  -- (k!)^4   396^(4k)
*/
int getPibylaman(int pi[], int n) {
    int sigma[100];
    newNum(sigma, 0);
    /*    99^2
    a is  -----
          ./ 8
    */
    int a[100];
    newNum(a, 99 * 99 * 99 * 99);
    divideInt(a, 8);
    sqrtNum(a);
    printNum(a);
    /*    (4k)!
    b is  -----
          (k!)^4
    */
    int b[100];
    newNum(b, 1);
    /*        1
    c is  -------- 
          396^(4k)
    */
    int c[100];
    newNum(c, 1);
    for(int k = 0; k < n; k++) {
        int delta[100];
        newNum(delta, 0);
        multiNum(b, c, delta);
        addNum(sigma, delta, sigma);
    }
    printNum(sigma);
    /*
     1   ./ 8  -- (4k)!  26390k + 1103
    -- = ----- > ------- -------------
    pi   99^2  -- (k!)^4   396^(4k)
            / -- (4k)!  26390k + 1103
    pi = a /  > ------- -------------
          /   -- (k!)^4   396^(4k)
    */
    divideNum(a, sigma, pi);
    return 0;
}
