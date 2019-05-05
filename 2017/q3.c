/** COMP0002 2017 Q3 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Q3(a)
 * malloc:
 *      Library function which requests the operating system to allocate a
 *      consecutive block of memory for the program; returns pointer to start of
 *      memory block upon success, returns NULL ptr upon failure.
 * free:
 *      Library function which informs the operating system to deallocate a
 *      block of memory starting at the given pointer, i.e. to tell the OS that
 *      the block of memory starting at the given pointer is no longer needed
 *      and can be marked as available for other programs to use.
 * cohesive function:
 *      A function is considered cohesive within a module if it is tightly
 *      related to other functions in the same module in terms of common
 *      responsibility / functionality. Usually, the function is also coupled to
 *      the shared data structures within the its residing module.
 * variable scope:
 *      The visibility of a symbol refering to a variable.
 * syntax:
 *      Rules of the C language which determins whether some sequence of
 *      characters is in fact a valid C program.
 */

// Q3(b)
// Assuming <string.h> library functions cannot be used
int lengthOfString(char* str)
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

char* copyString(char* str)
{
    int len = lengthOfString(str);
    char* copy = (char*) malloc(len * sizeof(char));

    for (int i = 0; i < len; i++)
        *(copy + i) = *(str + i);

    return copy;
}

int main(void)
{
    printf("Q3(b): length of \"test\" is %d\n", lengthOfString("test"));
    char* original = "123";
    char* copy = copyString(original);
    printf("Q3(b): copy of \"%s\" is \"%s\"\n", original, copy);
    free(copy);

    return 0;
}
