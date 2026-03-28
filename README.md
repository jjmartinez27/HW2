# HW2

## Author
Jaime Martinez

## Description
This program checks for possible floating-point overflow/precision loss in loops that use single-precision floating-point values.

The program takes two positive floating-point command-line arguments:
1. `loop_bound` - the stopping value of the loop
2. `loop_counter` - the increment value added each iteration

It prints the IEEE 754 single-precision bit representation of both inputs, determines whether possible overflow may occur, and if so prints the minimum overflow threshold in both floating-point and bit format.

## Instructions
Run the program with
./fp_overflow_checker loop_bound loop_counter

### Example
./fp_overflow_checker 1e+08 1.0

### Example Output
Loop bound:   0 10011001 01111101011110000100000
Loop counter: 0 01111111 00000000000000000000000

Warning: Possible overflow!
Overflow threshold:
1.67772e+07
0 10010111 00000000000000000000000
