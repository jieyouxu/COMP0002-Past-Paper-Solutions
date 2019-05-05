/** COMP0002 2017 */

#include <stdio.h>

//! Q1

// Q1a
//      1 * 2 * 3 / 4 * 5 - 6
// =    2 * 3 / 4 * 5 - 6
// =    6 / 4 * 5 - 6
// =    1 * 5 - 6
// =    5 - 6
// =    -1 (int)

// Q1b
// A segmentation fault occurs if an attempt is made by a user-space C program
// trying to access memory that is not owned by program. This causes the program
// to terminate (crash) due to the Operating System trying to prevent illegal
// memory access from corrupting memory of other user-space applications as well
// as the kernel or OS.

int main(void)
{
    printf("Q1a: %d\n", 1 * 2 * 3 / 4 * 5 - 6);

    return 0;
}
