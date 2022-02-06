#ifndef _STACK_H
#define _STACK_H
typedef LLIST STACK;

STACK createStack();        // create a stack
int isEmptyStack(STACK);    // check if stack is empty
STACK push(STACK, int);     // push an element to top of stack
STACK pop(STACK, int *);    // pop an element from top of stack and return it in *value
#endif