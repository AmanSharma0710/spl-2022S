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

int emptystack(stack S){
    if(S == NULL) return 1;
    else return 0;
}

int top(stack S){
    if(emptystack(S)){
        printf("Stack is empty\n");
        return 0;
    }
    else return S -> data;
}

stack push(stack S, int x){
    stack temp;
    temp = (stack)malloc(sizeof(node));
    temp -> data = x;
    temp -> next = S;
    return temp;
}

stack pop(stack S){
    if(emptystack(S)){
        printf("Stack is empty\n");
        return S;
    }
    else{
        stack temp;
        temp = S -> next;
        free(S);
        return temp;
    }
}

void printstack(stack S){
    if(emptystack(S)){
        printf("Stack is empty\n");
        return;
    }
    else{
        stack temp;
        temp = S;
        while(temp != NULL){
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

stack destroystack(stack S){
    node *p;
    while (S) {
    p = S; S = S -> next; free(p);
    }
    return NULL;
}