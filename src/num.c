#include"num.h"
#include<stdio.h>

//initialize the number array with a integer
//N[0] is the sign of the number(-1 for minus and +1 for plus)
//N[1] is the integer part of the number, and the rest of the array is the decimal part
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

//N = N * b;
int* multiInt(int N[], int b) {
	if(b < 0) {
		b = -b;
		N[0] = -N[0];
	}
	if(b == 1) {
		return N;
	}if(b > SCALE) {
		int higherPart = b / SCALE;
		int lowerPart = b % SCALE;
		int lowerNum[ARRAYLENGTH];
		copyNum(N, lowerNum);
		multiInt(N, higherPart);
		multiInt(N, SCALE);
		multiInt(lowerNum, lowerPart);
		return addNum(N, lowerNum, N);
	}
	int remain = 0;
	for(int i = ARRAYLENGTH-1; i >= 1; i--) {
		int currentBit = N[i] * b + remain;
		N[i] = currentBit % SCALE;
		remain = currentBit / SCALE;
		if(i == 1) {N[i] = currentBit;}
	}
	return N;
}


//c = a * b, return pointer to c, note that don't let either pointer b or a equals to c
int* multiNum(int a[], int b[], int c[]){
	newNum(c, 0);
	for(int i = 1; i < ARRAYLENGTH; i++){
		int ai[ARRAYLENGTH];
		copyNum(a, ai);
		multiInt(ai, b[i]);
		shiftRight(ai, (i - 1) * 3);
		addNum(c, ai, c);
	}
	c[0] = a[0] * b[0];
	return c;
}

//N = N / b;
int* divideInt(int N[], int b) {
	if(b < 0) {
		b = -b;
		N[0] = -N[0];
	}
	if(b == 1){return N;}
	int remain = 0;
	for(int i = 1; i < ARRAYLENGTH; i++){
		long currentBit = (N[i] + remain * SCALE);
		N[i] = currentBit / b;
		remain = currentBit % b;
		if(i == ARRAYLENGTH-1 && remain > SCALE/2){
			N[i]++;
		}
	}
	return N;
}

//c = a / b
int* divideNum(int a[], int b[], int c[]){
	newNum(c, 0);
	int leftOvers[ARRAYLENGTH];
	copyNum(a, leftOvers);
	leftOvers[0] = 1;
	int smallDivideNum[ARRAYLENGTH];
	copyNum(b, smallDivideNum);
	while(smallDivideNum[1] == 0) {
		multiInt(smallDivideNum, 10);
		multiInt(leftOvers, 10);
	}
	smallDivideNum[0] = -1;
	for(int i = 1; i < ARRAYLENGTH; i++){
		if(compareAbs(leftOvers, smallDivideNum) >= 0) {
			c[i] = leftOvers[i] / (smallDivideNum[i] + 1);
			int multipliedSmallDivideNum[ARRAYLENGTH];
			copyNum(smallDivideNum, multipliedSmallDivideNum);
			multiInt(multipliedSmallDivideNum, c[i]);
			addNum(leftOvers, multipliedSmallDivideNum, leftOvers);
			while(compareAbs(leftOvers, smallDivideNum) >= 0) {
				addNum(leftOvers, smallDivideNum, leftOvers);
				c[i]++;
			}
		}else {
			c[i] = 0;
		}
		divideInt(smallDivideNum, SCALE);
	}
	c[0] = a[0] * b[0];
	return c;
}

//c = a + b, return pointer to c, note that don't let pointer b equals to c
int* addNum(int a[], int b[], int c[]) {
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
		for(int i = ARRAYLENGTH-1; i > 1; i--) {
			c[i] = a[i] + b[i] + remain;
			remain = c[i] / SCALE;
			c[i] = c[i] % SCALE;
		}
		c[1] = a[1] + b[1] + remain;
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

int* sqrtNum(int a[]) {
	int precisionDelta[ARRAYLENGTH];
	newNum(precisionDelta, 3);
	shiftRight(precisionDelta, 3 * (ARRAYLENGTH - 4) - 1);

	int x[ARRAYLENGTH], lastX[ARRAYLENGTH], b[ARRAYLENGTH];
	newNum(x, 0);
	copyNum(a, lastX);
	int flag = 1;
	//x = 0.5(lastX + a / lastX)
	do{
		newNum(b, 0);
		divideNum(a, lastX, b);//b = a / lastX
		addNum(lastX, b, x);
		divideInt(x , 2);//x = 0.5(lastX + a / lastX)
		x[0] = -1;
		if(compareAbs(addNum(lastX, x, b), precisionDelta) == -1) {
			flag = 0;
		}
		x[0] = 1;
		copyNum(x, lastX);
	}while(flag);
	copyNum(x, a);
	return a;
}

//return 1 if a>b, -1 if a<b, 0 if a==b
int compareAbs(int a[], int b[]) {
	for(int i = 1; i < ARRAYLENGTH; i++){
		if(a[i] > b[i]){
			return 1;
		}else if(a[i] < b[i]){
			return -1;
		}
	}
	return 0;
}

void shiftRight(int N[], int n) {
	int shift = n / 3;
	for(int i = ARRAYLENGTH - 1; i > shift; i--){
		N[i] = N[i-shift];
	}
	for(int i = 1; i <= shift; i++){
		N[i] = 0;
	}
	for(int i = 0; i < (n % 3); i++){
		divideInt(N, 10);
	}
}

//copy a to b, return pointer of b
int* copyNum(int a[], int b[]){
	for(int i = 0; i < ARRAYLENGTH; i++){
		b[i] = a[i];
	}
	return b;
}

void printNum(int N[], int n) {
	if(N[0] < 0){
		printf("-");
	}
	printf("%d.", N[1]);
	for(int i = 2; i < n/3 + 2; i++){
		printf("%03d ", N[i]);
	};
	if(n%3 == 2) {
		printf("%d", N[n/3+2]/10);
	}else if(n%3 == 1) {
		printf("%d", N[n/3+2]/100);
	}
	printf("\n");
}