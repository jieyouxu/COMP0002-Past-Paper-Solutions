/** COMP0002 2018 Q3 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Q3(a)
 *  void:
 *      Keyword indicating no parameters, no return type and arbitrary type in
 *      the case of a (void *).
 *  linking:
 *      Linker combines object files produced from compilation and produce an
 *      executable file after resolving their dependencies.
 *  literal value:
 *      Expressions which represent exactly their corresponding value.
 *  function declaration:
 *      Designating a symbol with a list of parameters to refer to a procedure.
 */

/**
 * Q3(b)
 *  Linked List can be represented via node structs, with a key field and a
 *  pointer to the next node:
 */

typedef struct node
{
    int value;
    struct node* next;
} node;

void LinkedList_append(struct node* root, int value)
{
    if (root == NULL)
        return;

    struct node* newNode = malloc(sizeof(node));
    newNode->value = value;

    struct node* currentNode = root;
    while (currentNode->next != NULL)
        currentNode++;
    currentNode->next = newNode;
}

// Q3(c)

#define MIN(a, b) (a < b ? a : b)

int lengthOfString(char* s)
{
    if (s == NULL)
        return 0;

    int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

int find(char* s1, char* s2)
{
    if (s1 == NULL || s2 == NULL)
        return -1;

    int s1Length = lengthOfString(s1);
    int s2Length = lengthOfString(s2);
    int limit = s1Length - s2Length;

    for (int i = 0; i < limit; i++)
    {
        int matchedSegmentLength = 0;

        for (int j = 0; j < s2Length; j++)
        {
            if (s1[i + j] == s2[j])
                matchedSegmentLength++;

            if (matchedSegmentLength == s2Length)
                return i;
        }

        matchedSegmentLength = 0;
    }

    return -1;
}

int main(void)
{
    char* s1 = "This is a sentence";
    char* s2 = "sent";
    char* s3 = "as";
    printf("Q3(c): find(\"%s\", \"%s\") returns %d\n", s1, s2, find(s1, s2));
    printf("Q3(c): find(\"%s\", \"%s\") returns %d\n", s1, s3, find(s1, s3));

    return 0;
}
