/** COMP0012 2016B Q1 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Q1(a)
 * >        9 / 3 / 2 * 6 + 2 * 1.5
 *      =   3 / 2 * 6 + 2 * 1.5
 *      =   1 * 6 + 3.0
 *      =   6 + 3.0
 *      =   9.0
 *      double
 */

/**
 * Q1(b)
 * Given string representation of n characters where:
 * s[0] = length
 * s[1..n+1] = characters
 *
 * Q1(b)(i)
 *      The `char` array can hold both the length and character sequence because
 *      `char` is also an integer type. The length of the longest string is
 *      limited by the size of `char` on the architecture the program is running
 *      on, e.g. if `char` happens to be 1-byte, it can hold at most (2^8 - 1)
 *      which is the largest unsigned integer expressible by 8-bits with one
 *      reserved for the length at 0th index.
 */

// Q1(b)(ii)
int getLengthOfString(char* str)
{
    int len = 0;
    char* current = str;
    while (*current != '\0')
    {
        len++;
        current++;
    }
    return len;
}

// Q1(b)(iii)
char* copyString(char* str)
{
    if (str == NULL)
        return NULL;

    int len = getLengthOfString(str);
    char* copy = (char*) malloc(len * sizeof(char*));

    for (int i = 0; i < len; i++)
        *(copy + i) = *(str + i);

    return copy;
}

int main(void)
{
    printf("Q1(a): %f\n", 9 / 3 / 2 * 6 + 2 * 1.5);

    printf("Q1(b)(ii): length of \"test\" is %d \n", getLengthOfString("test"));

    char* s1 = "1234";
    char* s2 = copyString(s1);
    printf("Q1(b)(iii): copy of \"%s\" is \"%s\"\n", s1, s2);
    free(s2);

    return 0;
}
