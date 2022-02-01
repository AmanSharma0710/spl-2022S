#ifndef _HEAP_H
#define _HEAP_H
typedef struct _heap{
    int size;
    int capacity;
    int *arr;
}heap;

typedef heap *HEAP;

HEAP createHeap();              // create a heap
int isEmptyHeap(HEAP);          // check if the heap is empty
int isFullHeap(HEAP);           // check if the heap is full
int findMin(HEAP);              // find the minimum element in the heap
HEAP extractMin(HEAP);          // extract the minimum element in the heap
HEAP insertHeap(HEAP, int);     // insert an element in the heap
#endif