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

int main(void)
{
    int a[] = {-1, -4, 0, 6, -2};
    int aSum = sumNegatives(a, 5);
    printf("Sum of {-1, -4, 0, 6, -2} is %d\n", aSum);

    return 0;
}
