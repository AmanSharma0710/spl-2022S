#include<stdio.h>
#include<stdlib.h>
#include "llist.h"
#include "stack.h"

STACK createStack(){
    STACK s = createList();
    return s;
}     
int isEmptyStack(STACK s){
    return isEmpty(s);
} 
STACK push(STACK s, int value){     //This is O(1) time
    insertAtFront(s, value);
    return s;
}  
STACK pop(STACK s, int *value){     //This is O(1) time
    if(isEmptyStack(s)){
        printf("Stack is empty\n");
        *value = -1;
    }
    else{
        deleteFromFront(s, value);
    }
    return s;
}