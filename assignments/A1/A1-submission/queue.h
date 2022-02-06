#ifndef _QUEUE_H
#define _QUEUE_H
typedef LLIST QUEUE;

QUEUE createQueue();            // create a queue
int isEmptyQueue(QUEUE);        // check if queue is empty
QUEUE enqueue(QUEUE, int);      // add an element to the back of the queue
QUEUE dequeue(QUEUE, int *);    // remove an element from the front of the queue and return the element through the pointer
#endif