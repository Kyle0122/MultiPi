#define SCALE 1000

/* About high percision number:
There are five function to calculate high percision number array: Add, multiply, divide, sqrt, compareAbs.

In num.h, the length of the array is arbitrary. N[0] is the sign of the number(-1 for minus and +1 for plus), 
N[1] is the integer part of the number, and the rest of the array is the decimal part.
In this way the total digit represent by the array is 3*(length - 2).

Note that there are some limits about the high percision number functions:
1) In the divide(int* N, b) function, b should be less than or equal to 2^31/SCALE, which is 21474.
2) In the multiply(int* N, b) function, b shoule be less than or equal to 2^31/SCALE, which is 21474
2) the interger part has the maximum value of 2^31.
*/

int* newNum(int N[], int a, int length);

int* multiInt(int N[], int b, int length);

int* multiNum(int a[], int b[], int c[], int length);

int* divideInt(int N[], int b, int length);

int* divideNum(int a[], int b[], int c[], int length);

int* addNum(int a[], int b[], int c[], int length);

int* sqrtNum(int N[], int length);

int compareAbs(int a[], int b[], int length);

void shiftRight(int N[], int n, int length);

int* copyNum(int a[], int b[], int length);

void printNum(int N[], int n);