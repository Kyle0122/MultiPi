#include"num.h"
#include<stdio.h>

//initialize the number array with a integer
//N[0] is the sign of the number(-1 for minus and +1 for plus)
//N[1] is the integer part of the number, and the rest of the array is the decimal part
int* newNum(int N[], int a, int length) {
	if(a < 0) {
		N[0] = -1;
		N[1] = -a;
	}else {
		N[0] = 1;
		N[1] = a;
	}
	for(int i = 2; i < length; i++){
		N[i] = 0;
	}
	return N;
}

//N = N * b;
int* multiInt(int N[], int b, int length) {
	if(b < 0) {
		b = -b;
		N[0] = -N[0];
	}
	if(b == 1) {
		return N;
	}if(b > SCALE) {
		int higherPart = b / SCALE;
		int lowerPart = b % SCALE;
		int lowerNum[length];
		copyNum(N, lowerNum, length);
		multiInt(N, higherPart, length);
		multiInt(N, SCALE, length);
		multiInt(lowerNum, lowerPart, length);
		return addNum(N, lowerNum, N, length);
	}
	int remain = 0;
	for(int i = length-1; i >= 1; i--) {
		int currentBit = N[i] * b + remain;
		N[i] = currentBit % SCALE;
		remain = currentBit / SCALE;
		if(i == 1) {N[i] = currentBit;}
	}
	return N;
}


//c = a * b, return pointer to c, note that don't let either pointer b or a equals to c
int* multiNum(int a[], int b[], int c[], int length){
	newNum(c, 0, length);
	for(int i = 1; i < length; i++){
		int ai[length];
		copyNum(a, ai, length);
		multiInt(ai, b[i],length);
		shiftRight(ai, (i - 1) * 3, length);
		addNum(c, ai, c, length);
	}
	c[0] = a[0] * b[0];
	return c;
}

//N = N / b;
int* divideInt(int N[], int b, int length) {
	if(b < 0) {
		b = -b;
		N[0] = -N[0];
	}
	if(b == 1){return N;}
	int remain = 0;
	for(int i = 1; i < length; i++){
		long currentBit = (N[i] + remain * SCALE);
		N[i] = currentBit / b;
		remain = currentBit % b;
		if(i == length-1 && remain > SCALE/2){
			N[i]++;
		}
	}
	return N;
}

//c = a / b
int* divideNum(int a[], int b[], int c[], int length){
	newNum(c, 0, length);
	int leftOvers[length];
	copyNum(a, leftOvers, length);
	leftOvers[0] = 1;
	int smallDivideNum[length];
	copyNum(b, smallDivideNum, length);
	while(smallDivideNum[1] == 0) {
		multiInt(smallDivideNum, 10, length);
		multiInt(leftOvers, 10, length);
	}
	smallDivideNum[0] = -1;
	for(int i = 1; i < length; i++){
		if(compareAbs(leftOvers, smallDivideNum, length) >= 0) {
			c[i] = leftOvers[i] / (smallDivideNum[i] + 1);
			int multipliedSmallDivideNum[length];
			copyNum(smallDivideNum, multipliedSmallDivideNum, length);
			multiInt(multipliedSmallDivideNum, c[i], length);
			addNum(leftOvers, multipliedSmallDivideNum, leftOvers, length);
			while(compareAbs(leftOvers, smallDivideNum, length) >= 0) {
				addNum(leftOvers, smallDivideNum, leftOvers, length);
				c[i]++;
			}
		}else {
			c[i] = 0;
		}
		divideInt(smallDivideNum, SCALE, length);
	}
	c[0] = a[0] * b[0];
	return c;
}

//c = a + b, return pointer to c, note that don't let pointer b equals to c
int* addNum(int a[], int b[], int c[], int length) {
	//variable ab represents the relation between abs(a) and abs(b)
	int ab = compareAbs(a, b, length);
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
		return newNum(c, 0, length);
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
		for(int i = length-1; i > 1; i--) {
			c[i] = a[i] + b[i] + remain;
			remain = c[i] / SCALE;
			c[i] = c[i] % SCALE;
		}
		c[1] = a[1] + b[1] + remain;
	}else if(doAdd == -1){
		int remain = 0;
		for(int i = length-1; i >= 1; i--) {
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

int* sqrtNum(int a[], int length) {
	int precisionDelta[length];
	newNum(precisionDelta, 3, length);
	shiftRight(precisionDelta, 3 * (length - 4) - 1, length);

	int x[length], lastX[length], b[length];
	newNum(x, 0, length);
	copyNum(a, lastX, length);
	int flag = 1;
	//x = 0.5(lastX + a / lastX)
	do{
		newNum(b, 0, length);
		divideNum(a, lastX, b, length);//b = a / lastX
		addNum(lastX, b, x, length);
		divideInt(x , 2, length);//x = 0.5(lastX + a / lastX)
		x[0] = -1;
		if(compareAbs(addNum(lastX, x, b, length), precisionDelta, length) == -1) {
			flag = 0;
		}
		x[0] = 1;
		copyNum(x, lastX, length);
	}while(flag);
	copyNum(x, a, length);
	return a;
}

//return 1 if a>b, -1 if a<b, 0 if a==b
int compareAbs(int a[], int b[], int length) {
	for(int i = 1; i < length; i++){
		if(a[i] > b[i]){
			return 1;
		}else if(a[i] < b[i]){
			return -1;
		}
	}
	return 0;
}

void shiftRight(int N[], int n, int length) {
	int shift = n / 3;
	for(int i = length - 1; i > shift; i--){
		N[i] = N[i-shift];
	}
	for(int i = 1; i <= shift; i++){
		N[i] = 0;
	}
	for(int i = 0; i < (n % 3); i++){
		divideInt(N, 10, length);
	}
}

//copy a to b, return pointer of b
int* copyNum(int a[], int b[], int length){
	for(int i = 0; i < length; i++){
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
		printf("%02d", N[n/3+2]/10);
	}else if(n%3 == 1) {
		printf("%01d", N[n/3+2]/100);
	}
	printf("\n");
}