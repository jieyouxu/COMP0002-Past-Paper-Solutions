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
    node* next;
} node;

void LinkedList_append(node* root, int value)
{
    if (root == NULL)
        return;

    node* newNode = malloc(sizeof(node));
    newNode->value = value;

    node* currentNode = root;
    while (currentNode->next != NULL)
        currentNode++;
    currentNode->next = newNode;
}
