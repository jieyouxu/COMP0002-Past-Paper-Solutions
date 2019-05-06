/** COMP0002 Q4 */

#include <stdio.h>

/**
 * Q4(a)
 * virtual memory:
 *      Memory managed by the operating system such that how a virtual memory
 *      address is mapped to a physical memory address is managed by the OS.
 * free:
 *      Signal to the OS that a certain memory block starting at a given memory
 *      address is no longer needed by the program, and can be deallocated.
 * compound statement:
 *      A statement list composed from multiple statements.
 * variable declaration:
 *      Designating a new symbol able to hold values of a specific type.
 */

/**
 * Q4(b)
 *
 * Given
 *  1.  int f(int n)
 *  2.      if (n < 1) { return 0; }
 *  3.      else
 *  4.          n(n-1) + f(n-1);
 *  5.      return 0;
 *  6.  }
 *
 * Q4(b)(i)
 *
 * 1. Missing left brace, should be
 *      int f(int n) {
 * 4. Missing `*`, should be
 *      n * (n - 1) + f(n - 1)
 *
 * Q4(b)(ii)
 *
 * 2. Base case should be 1
 *      2^0 = 1
 * 4. Step case should be
 *      f(n - 1) + f(n - 1), or more efficiently 2 * f(n - 1)
 */

// Q3(c)
//
//  HIGH ADDRESS -------> +---------------------------+
//                        |                           | COMMAND-LINE ARGUMENTS
//                        |                           | ENVIRONMENT VARIABLES
//                        |---------------------------|
//                        |           STACK           |
//                        |                           |
//                        |- - - - - - - - - - - - - -|
//                        |             |             |
//                        |             |             |
//                        |             V             |
//                        |                           |
//                        |                           |
//                        |                           |
//                        |                           |
//                        |                           |
//                        |                           |
//                        |             ^             |
//                        |             |             |
//                        |             |             |
//                        | - - - - - - - - - - - -  -|
//                        |                           |
//                        |           HEAP            |
//                        |---------------------------|   ^
//                        |                           |   | INITIALIZED TO ZERO
//                        |     UNINITIALIZED DATA    |   | BY `EXEC`
//                        |                           |   |
//                        |---------------------------|   V
//                        |                           |   ^
//                        |      INITIALIZED DATA     |   |
//                        |                           |   |
//                        |---------------------------|   | READ FROM
//                        |                           |   | PROGRAM FILE
//                        |           TEXT            |   | BY `EXEC`
//                        |                           |   |
//   LOW ADDRESS -------> +---------------------------+   V
//

// Q3(d)
void filledTriangle(int rows)
{
    if (rows < 1)
        return;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("%c", '*');

        printf("\n");
    }
}

int main(void)
{
    printf("Q4(d):\n");
    printf("filledTriangle(4):\n");
    filledTriangle(4);
    printf("filledTriangle(6):\n");
    filledTriangle(6);

    return 0;
}
