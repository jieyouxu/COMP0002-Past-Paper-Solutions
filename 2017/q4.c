/** COMP0002 2017 Q4 */

#include <stdio.h>

/**
 * Q4(a)
 *
 * variable lifetime:
 *      The time period with respect to the program that the variable refers to
 *      a valid memory address, given that the variable is declared and visible.
 * file scope:
 *      After some symbol is declared, the symbol is visible to all subsequent
 *      parts of the program in the same translation unit.
 * dereference:
 *      Retrieving the value stored at the memory address referenced by a
 *      pointer.
 * heap memory:
 *      Memory which can be dynamically allocated by the program.
 */

// Q4(b)
// Given
// 1. void printAsBinary(int n)
// 2. {
// 3.   int remainder;
// 4.   int i = 1;
// 5.
// 6.   while(n != 0)
// 7.   {
// 8.       remainder = n % 2;
// 9.       n = n / 2;
// 10.      printf("%d", remainder);
// 11.      i = i * 10;
// 12.  }
// 13.}
// Which is supposed to print 5 as 101 in binary.

// Q4(b)(i)
// >>> printAsBinary(5)
// >>> "10"
// ITER 0:
//      remainder = 5 % 2; // remainder = 1
//      n = 5 / 2;         // n = 2
//      printf("%d", 1);   // "1"
//      i = 1 * 10         // i = 10
// ITER 1:
//      remainder = 2 % 2; // remainder = 0
//      n = 2 / 2;         // n = 0
//      printf("%d", 0);   // "10"
//      i = 1 * 10         // i = 100
// Which means that the loop prematurely terminates.

// Q4(b)(ii)
void printAsBinary(int n)
{
    if (n / 2 == 0)
    {
        int remainder = n % 2;
        printf("%d\n", remainder);
        return;
    }

    int remainder = n % 2;
    printf("%d", remainder);
    int halved = n / 2;
    return printAsBinary(halved);
}

/**
 * Q4(c)
 *
 * virtual memory:
 *      Important for multiple C programs running on the same computer at the
 *      same time to prevent programs from interferring with each other, e.g. so
 *      illegal access from program A won't corrupt memory managed by program B.
 *      This is also for security reasons so program A cannot access memory *
 *      managed by program B.
 */

int main(void)
{
    printf("Q4(b)(ii): 5 in binary is ");
    printAsBinary(5);

    return 0;
}
