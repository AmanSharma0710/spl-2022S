#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "stack.h"

stack initstack(){
    stack S;
    S = (stack)malloc(sizeof(node));
    S -> data = 0; S -> next = NULL;
    return S;
}

int empty(stack S){
    if (S -> next == NULL) return 1;
    else return 0;
}

int top(stack S){
    if (empty(S)) return 0;
    else return S -> next -> data;
}

stack push(stack S, int x){
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode -> data = x;
    newnode -> next = S -> next;
    S -> next = newnode;
    return S;
}

stack pop(stack S){
    node *temp;
    if (empty(S)) return S;
    temp = S -> next;
    S -> next = temp -> next;
    free(temp);
    return S;
}

void printstack(stack S){
    node *temp;
    temp = S -> next;
    printf("Printing stack: ");
    while (temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}


stack destroystack(stack S){
    node *p;
    while (S) {
    p = S; S = S -> next; free(p);
    }
    return NULL;
}