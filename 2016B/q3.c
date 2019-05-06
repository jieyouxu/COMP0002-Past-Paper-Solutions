/** COMP0002 2016B Q3 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Q3(a)
 *
 * stack frame:
 *      Represents function call:
 *          - Return address (last invoking address)
 *          - Arguments data
 *          - Local variables
 * local scope:
 *      Visiblity within a function or a block.
 * pointer arithmetic:
 *      Ability to offset memory address relative to a base address via addition
 *      and subtraction.
 * function definition:
 *      Implementing the actual body of a function.
 */

/**
 * Q3(b)
 *  (i)     double a = 12;  YES
 *  (ii)    long n = 2.3;   FAIL: implicit conversion
 *  (iii)   int k = &12;    FAIL: address-of operator on constant
 */

/**
 * Q3(c)(i)
 *  A linked list have be constructed in C via a `struct` by having a struct
 *  consist of some payload, together with a pointer to the next struct. A
 * struct serves as a node.
 */

// Q3(c)(ii)
typedef struct node
{
    char* stringValue;
    int intValue;
    node* next;
} node;

// Q3(c)(iii)
// Given linked list always has root node
node* createNode(char* stringValue, int* intValue)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->stringValue = stringValue;
    newNode->intValue = intValue;
    return newNode;
}

node* LinkedList_append(node* root, char* stringValue, int intValue)
{
    node* newNode = createNode(stringValue, intValue);

    node* currentNode = root;
    while (currentNode->next != NULL)
        currentNode = currentNode->next;
    currentNode->next = newNode;

    return root;
}
