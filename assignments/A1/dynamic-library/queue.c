#include<stdio.h>
#include<stdlib.h>
#include <llist.h>
#include <queue.h>

QUEUE createQueue(){
    QUEUE q = createList();
    return q;
}

int isEmptyQueue(QUEUE q){
    return isEmpty(q);
}

QUEUE enqueue(QUEUE q, int value){          //Since we are storing the tail of the linked list too, enqueue can be done in O(1) time instead of O(n)
    insertAtEnd(q, value);
    return q;
}

QUEUE dequeue(QUEUE q, int *value){         //This is O(1) time
    if(isEmptyQueue(q)){
        printf("Queue is empty\n");
        *value = -1;
    }
    else{
        deleteFromFront(q, value);
    }
    return q;
}