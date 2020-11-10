#include <stdio.h>
#include "num.h"

/*BBP formula，--  1     4      2      1      1
        pi =   > ---- (---- - ---- - ---- - ----)
               --16^k  8k+1   8k+4   8k+5   8k+6
*/
int getPibyBBP(int pi[], int precision) {
	int length = precision/3 + 8;
	newNum(pi, 0, length);
	int precisionDelta[length];
	newNum(precisionDelta, 4, length);
	shiftRight(precisionDelta, precision + 1, length);
	//printNum(precisionDelta, precision + 1);
	int k;
	for(k = 0; k < 1000000; k++) {
		int a[length];divideInt(newNum(a, 4, length), (8*k +1), length);
		int b[length];divideInt(newNum(b, 2, length), (8*k +4), length);
		int c[length];divideInt(newNum(c, 1, length), (8*k +5), length);
		int d[length];divideInt(newNum(d, 1, length), (8*k +6), length);
		int delta1[length];addNum(addNum(b, c, delta1, length), d, delta1, length);
		int delta[length]; addNum(a, multiInt(delta1, -1, length), delta, length);
		for(int i = 0; i<k; i++){
			divideInt(delta, 16, length);
		}
		addNum(pi, delta, pi, length);
		if(compareAbs(delta, precisionDelta, length) == -1){
			break;
		}
	}

	return k;
}

int getPibyLeibniz(int pi[], int precision) {
	int length = precision/3 + 6;
	newNum(pi, 0, length);
	/*initialize a small number to be precisionDelta*/
	int precisionDelta[length];
	newNum(precisionDelta, 4, length);
	shiftRight(precisionDelta, precision + 1, length);

	int k = 0;
	for (k = 0; k < 1000000000; k++) {
		int delta[length];
		newNum(delta, 1, length);
		divideInt(delta, (2 * k + 1), length);
		if (k % 2 == 1) {
			delta[0] = -1;
		}
		multiInt(delta, 4, length);
		addNum(pi, delta, pi, length);
		if(compareAbs(delta, precisionDelta, length) == -1){
			break;
		}
	}
	return k;
}

int getPibyEuler(int pi[], int precision) {
	int length = precision/3 + 6;
	newNum(pi, 0, length);
	/*initialize a small number to be precisionDelta*/
	int precisionDelta[length];
	newNum(precisionDelta, 1, length);
	shiftRight(precisionDelta, (precision) * 2, length);

	int delta[length];
	int k;
	for(k = 1; k < 1000000000; k++) {
		newNum(delta, 6, length);
		divideInt(delta, k, length);
		divideInt(delta, k, length);
		addNum(pi, delta, pi, length);
		
		if(compareAbs(delta, precisionDelta, length) == -1){
			break;
		}/*
		if(k%1000 == 0){
			printf("Euler, n=%d,\tdelta:", k);
			printNum(delta, 30);
			copyNum(pi, delta);
			sqrtNum(delta);
			printNum(delta, 30);
		}*/
	}
	sqrtNum(pi, length);
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
int getPibyLaman(int pi[], int precision) {
	int length = precision/3 + 6;
	newNum(pi, 3, length);
	/*initialize a small number to be precisionDelta*/
	int precisionDelta[length];
	newNum(precisionDelta, 4, length);
	shiftRight(precisionDelta, precision + 1, length);
	/*    99^2
	a is  -----
		  ./ 8
	*/
	int a[length];
	newNum(a, 1, length);
	sqrtNum(divideInt(a, 8, length), length);
	multiInt(a, 99*99, length);
	/*         (4k)!
	b is  ----------------
          (k!)^4 * 396^(4x)
	*/
	int b[length], sigma[length], delta[length];
	newNum(b, 1, length);
	newNum(sigma, 0, length);
	for(int k = 0; k < 1000; k++) {
		copyNum(b, delta, length);
		multiInt(delta, 26390 * k + 1103, length);
		addNum(sigma, delta, sigma, length);
		/*
		1   ./ 8  -- (4k)!  26390k + 1103
		-- = ----- > ------- -------------
		pi   99^2  -- (k!)^4   396^(4k)
		thus:
				/ -- (4k)!  26390k + 1103
		pi = a /  > ------- -------------
			/   -- (k!)^4   396^(4k)
		*/
		divideNum(a, sigma, delta, length);
		delta[0] = -1;
		if(compareAbs(addNum(delta, pi, delta, length), precisionDelta, length) == -1 ){
			return k;
		}else {
			divideNum(a, sigma, pi, length);
		}
		/*             (4k + 1)* (4k + 2)* (4k + 3)* (4k + 4)
		b[k+1] = b[k] -----------------------------------------
					  (k + 1)* (k + 1)* (k + 1)* (k + 1) *396^4
		*/
		multiInt(b, (4*k + 1)*(4*k + 2)*(4*k + 3)*(4*k + 4), length);
		divideInt(b, (k + 1)*(k + 1)*(k + 1)*(k + 1), length);
		divideInt(b, 396*396, length);
		divideInt(b, 396*396, length);
	}
	
	divideNum(a, sigma, pi, length);
	return 0;
}
