#define SCALE 1000
#define ARRAYLENGTH 200
/* About high percision number:
There are five function to calculate high percision number array: Add, multiply, divide, compareAbs.

In num.h, ARRAYLENGTH is the length of the array used to represent the percise number.
N[0] is the sign of the number(-1 for minus and +1 for plus), N[1] is the integer part of the number,
and the rest of the array is the decimal part.In this way the total digit represent by the array is 3*(ARRAYLENGTH - 2).

Note that there are some limits about the high percision number functions:
1) In the divide(int* N, b) function, b should be less than or equal to 2^31/SCALE, which is 21474.
2) In the multiply(int* N, b) function, b shoule be less than or equal to 2^31/SCALE, which is 21474
2) the interger part has the maximum value of 2^31.
*/

int* newNum(int N[], int a);

int* multiInt(int N[], int b);

int* multiNum(int a[], int b[], int c[]);

int* divideInt(int N[], int b);

int* divideNum(int a[], int b[], int c[]);

int* addNum(int a[], int b[], int c[]);

int* sqrtNum(int N[]);

int compareAbs(int a[], int b[]);

void shiftRight(int N[], int n);

int* copyNum(int a[], int b[]);

void printNum(int N[]);