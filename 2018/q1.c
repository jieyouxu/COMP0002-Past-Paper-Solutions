/** COMP0002 2018 Q1 */

#include <stdio.h>

/**
 * Q1(a)
 *      > 10 / 2 + 25 / 5 * 0.5
 *      = 5 + 5 * 0.5
 *      = 5 + 2.5
 *      = 7.5
 */

// Q1(b)
int sumNegatives(int numbers[], int length)
{
    if (length < 1)
        return 0;

    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        if (numbers[i] < 0)
            sum += numbers[i];
    }

    return sum;
}

/**
 * Q1(c)(i)
 *      Indexing starts at zero because indexing is offset from base address
 *      from the start of the memory block allocated for the array.
 * Q1(c)(ii)
 *      Given some arbitrary array n:
 *      Base case (n[0]):
 *          n[0] === *n === *(n + 0)
 *      Inductive case (n[i]) for i > 0:
 *          n[i] === *(n + i)
 */

// Q1(c)(iii)
int sumNegativesPointer(int* numbers, int length)
{
    if (length < 1)
        return 0;

    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        if (*(numbers + i) < 0)
            sum += *(numbers + i);
    }

    return sum;
}

int main(void)
{
    int a[] = {-1, -4, 0, 6, -2};
    int aSum = sumNegatives(a, 5);
    printf("Q1(b) Sum of {-1, -4, 0, 6, -2} is %d\n", aSum);
    int aSumPtr = sumNegativesPointer(a, 5);
    printf("Q1(c)(iii) Sum of {-1, -4, 0, 6, -2} is %d\n", aSumPtr);

    return 0;
}
