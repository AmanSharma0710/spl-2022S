#include<stdio.h>
#include<stdlib.h>
#include <heap.h>

const int HEAP_SIZE = 100;

HEAP createHeap(){
    HEAP h;
    h = (HEAP)malloc(sizeof(struct _heap));
    h->size = 0;
    h->capacity = HEAP_SIZE;
    h->arr = (int*)malloc(sizeof(int)*HEAP_SIZE);
    return h;
}

int isEmptyHeap(HEAP h){
    return h->size == 0;
}

int isFullHeap(HEAP h){
    return h->size == h->capacity;
}

int findMin(HEAP h){
    if(isEmptyHeap(h)){
        printf("Heap is empty\n");
        return -1;
    }
    return h->arr[0];
}

HEAP heapify(HEAP h, int i){        // i is the index of the node to be heapified
    int left = 2*i + 1;
    int right = 2*i + 2;
    int smallest = i;   
    if(left < h->size && h->arr[left] < h->arr[smallest]){
        smallest = left;
    }
    if(right < h->size && h->arr[right] < h->arr[smallest]){
        smallest = right;
    }
    if(smallest != i){              //if the value in the node is not the smallest, swap it with the smallest value from its children and heapify again
        int temp = h->arr[i];
        h->arr[i] = h->arr[smallest];
        h->arr[smallest] = temp;
        heapify(h, smallest);
    }
    return h;
}

HEAP extractMin(HEAP h){
    if(isEmptyHeap(h)){
        printf("Heap is empty\n");
        return h;
    }
    h->arr[0] = h->arr[h->size-1];    //swap the last element with the first element
    h->size--;
    heapify(h, 0);                      //heapify the root
    return h;
}

HEAP insertHeap(HEAP h, int value){
    if(isFullHeap(h)){
        printf("Heap is full\n");
        return h;
    }
    h->arr[h->size] = value;
    h->size++;
    int i = h->size - 1;
    while(i > 0 && h->arr[i] < h->arr[(i-1)/2]){  //if the value is smaller than its parent, swap it with its parent and keep doing it until root to maintain heap property
        int temp = h->arr[i];
        h->arr[i] = h->arr[(i-1)/2];
        h->arr[(i-1)/2] = temp;
        i = (i-1)/2;
    }
    return h;
}