#include <stdio.h>
#include "num.h"

/*BBP formula，--  1     4      2      1      1
        pi =   > ---- (---- - ---- - ---- - ----)
               --16^4  8k+1   8k+4   8k+5   8k+6
*/
int getPibyBBP(int pi[], int precision){
	newNum(pi, 0);
	int precisionDelta[ARRAYLENGTH];
	newNum(precisionDelta, 4);
	shiftRight(precisionDelta, precision + 1);
	int k;
	for(k = 0; k < 1000000; k++) {
		int a[ARRAYLENGTH];divideInt(newNum(a, 4), (8*k +1));
		int b[ARRAYLENGTH];divideInt(newNum(b, 2), (8*k +4));
		int c[ARRAYLENGTH];divideInt(newNum(c, 1), (8*k +5));
		int d[ARRAYLENGTH];divideInt(newNum(d, 1), (8*k +6));
		int delta1[ARRAYLENGTH];addNum(addNum(b, c, delta1), d, delta1);
		int delta[ARRAYLENGTH]; addNum(a, multiInt(delta1, -1), delta);
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
	int precisionDelta[ARRAYLENGTH];
	newNum(precisionDelta, 4);
	shiftRight(precisionDelta, precision + 1);

	int k = 0;
	for (k = 0; k < 1000000000; k++) {
		int delta[ARRAYLENGTH];
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
	int precisionDelta[ARRAYLENGTH];
	newNum(precisionDelta, 1);
	shiftRight(precisionDelta, (precision) * 2 );

	int delta[ARRAYLENGTH];
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
高精度库的整数部分的最大值为Int类型最大值，
所以在下面用b来存储公式中和阶乘和指数相关的部分,
它是小于1的高精度小数。
*/
int getPibylaman(int pi[], int n) {
	int sigma[ARRAYLENGTH];
	newNum(sigma, 0);
	/*    99^2
	a is  -----
		  ./ 8
	*/
	int a[ARRAYLENGTH];
	newNum(a, 1);
	sqrtNum(divideInt(a, 8));
	multiInt(a, 99*99);
	/*         (4k)!
	b is  ----------------
          (k!)^4 * 396^(4x)
	*/
	int b[ARRAYLENGTH];
	newNum(b, 1);
	for(int k = 0; k < n; k++) {
		int delta[ARRAYLENGTH];
		copyNum(b, delta);
		multiInt(delta, 26390 * k + 1103);
		addNum(sigma, delta, sigma);
		/*             (4k + 1)* (4k + 2)* (4k + 3)* (4k + 4)
		b[k+1] = b[k] -----------------------------------------
					  (k + 1)* (k + 1)* (k + 1)* (k + 1) *396^4
		*/
		multiInt(b, (4*k + 1)*(4*k + 2)*(4*k + 3)*(4*k + 4));
		divideInt(b, (k + 1)*(k + 1)*(k + 1)*(k + 1));
		divideInt(b, 396*396);
		divideInt(b, 396*396);
	}
	/*
	 1   ./ 8  -- (4k)!  26390k + 1103
	-- = ----- > ------- -------------
	pi   99^2  -- (k!)^4   396^(4k)
	thus:
			/ -- (4k)!  26390k + 1103
	pi = a /  > ------- -------------
		  /   -- (k!)^4   396^(4k)
	*/
	divideNum(a, sigma, pi);
	return 0;
}
