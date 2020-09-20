# MultiPi
calculate Pi in multiple ways

# Build
$make

# Build and Run
$make run

# About high percision number:
in num.h, ARRAYLENGTH is the length of the array used to represent the percise number. N[0] is the sign of the number(-1 for minus and +1 for plus), N[1] is the integer part of the number, and the rest of the array is the decimal part, the last number in the array is omitted sence it is usually unprecice. In this way the total digit represent by the array is 5*(ARRAYLENGTH-3).