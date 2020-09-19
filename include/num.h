#define SCALE 100000
#define SCALELENGTH 5
//the maxi value of SCALE is half the maxi value of int
//the SCALELENGTH is the length of SCALE

int* newNum(int N[], int a);

void multiply(int N[], int b);

void divide(int N[], int b);

int* add(int a[], int b[], int c[]);

int* subtract(int a[], int b[], int c[]);

int compare(int a[], int b[]);

void printNum(int N[]);