# MultiPi
calculate Pi in multiple ways

# Build
$make

# Build and Run
$make run

# About high percision number:
There are five function to calculate high percision number array: Add, multiply, divide, compareAbs.

In num.h, ARRAYLENGTH is the length of the array used to represent the percise number. N[0] is the sign of the number(-1 for minus and +1 for plus), N[1] is the integer part of the number, and the rest of the array is the decimal part, the last two numbers in the array is omitted sence they may be unprecice. In this way the total digit represent by the array is 5*(ARRAYLENGTH-4).

Note that there are two limits about the high percision number functions: 1) In the divide(int* N, b) function, b should be less than or equal to 2^31/SCALE, which is 21474. 2) the interger part has the maximum value of 2^31.