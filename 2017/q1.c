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

// Q1c
// Given m, n are valid indices
void swap(int a[], int m, int n)
{
    int temp = a[m];
    a[m] = a[n];
    a[n] = temp;
}

int main(void)
{
    printf("Q1(a): %d\n", 1 * 2 * 3 / 4 * 5 - 6);

    int a[] = {3, 5, 7, 9, 11};
    swap(a, 2, 3);
    printf("Q1(c): ");
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
