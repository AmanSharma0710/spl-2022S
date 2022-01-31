#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "queue.h"

queue initqueue(){
    queue Q;
    node *p;
    p = (node *)malloc(sizeof(node));
    p -> data = 0;
    p -> next = NULL;
    Q.front = Q.back = p;
    return Q;
}

int emptyqueue(queue Q){
    if (Q.front == Q.back) return 1;
    else return 0;
}

int front(queue Q){
    if (emptyqueue(Q)) return 0;
    else return Q.front -> data;
}

queue enqueue(queue Q, int x){
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode -> data = x;
    newnode -> next = NULL;
    Q.back -> next = newnode;
    Q.back = newnode;
    return Q;
}

queue dequeue(queue Q){
    node *temp;
    if (emptyqueue(Q)) return Q;
    temp = Q.front;
    Q.front = Q.front -> next;
    free(temp);
    return Q;
}

void printqueue(queue Q){
    node *temp;
    temp = Q.front;
    printf("Printing queue: ");
    while (temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

queue destroyqueue(queue Q){
    node *p;
    while (Q.front) {
    p = Q.front;
    Q.front = (Q.front) -> next;
    free(p);
    }
    Q.front = Q.back = NULL;
    return Q;
}