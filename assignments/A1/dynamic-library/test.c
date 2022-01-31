#include<stdio.h>
#include<stdlib.h>
#include "llist.h"
#include "queue.h"


int main(){
    QUEUE q = createQueue();
    printf("%d\n", isEmptyQueue(q));
    enqueue(q, 1);
    printf("%d\n", isEmptyQueue(q));
    enqueue(q, 2);
    enqueue(q, 3);
    while(!isEmptyQueue(q)){
        int value;
        dequeue(q, &value);
        printf("%d\n", value);
    }
    return 0;
}