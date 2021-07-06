# C-AppliedDFS-implementation
 This is a program that counts "towns" and sorts it by it's size in ascending order.
 The number1 means an occupied block and number 0 means a vacant block. A collection of occupied blocks is a town. Two continuously
 occupied blocks in any 4 cardinal directions are considered as connected, except for the 4 diagonal directions.
# Input and output
 Input: Inputs a NxN square, where 5≤N≤25, in the first line, and inputs N number of 0's or 1's in each N lines.
 Output: Prints the number of towns in the first and then prints the number of occupied blocks in each town line by line in ascending order.
# Sample input
 7
 0110100
 0110101
 1110101
 0000111
 0100000
 0111110
 0111000
# Sample output
 Number of towns: 3
 Town 1: 7 blocks
 Town 2: 8 blocks
 Town 3: 9 blocks