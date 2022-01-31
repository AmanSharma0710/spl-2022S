#include<stdio.h>
#include<stdlib.h>
#include "llist.h"

LLIST createList(){
    LLIST l;
    l = (LLIST)malloc(sizeof(struct _llist));
    l->head = NULL;
    l->tail = NULL;
    return l;
}

int isEmpty(LLIST l){
    if(l->head == NULL)
        return 1;
    else
        return 0;
}

int searchList(LLIST l, int key){
    if(isEmpty(l))
        return 0;
    NODE *p = l->head;
    while(p!=NULL){
        if(p->data == key)
            return 1;
        p = p->next;
    }
    return 0;
}

LLIST insertAtFront(LLIST l, int key){
    NODE *p = (NODE*)malloc(sizeof(struct _node));
    p->data = key;
    p->next = l->head;
    l->head = p;
    if(l->tail == NULL)         // if list is empty, make tail point to the new node
        l->tail = p;
    return l;
}

LLIST insertAtEnd(LLIST l, int key){
    NODE *p = (NODE*)malloc(sizeof(struct _node));
    p->data = key;
    p->next = NULL;
    if(isEmpty(l)){
        l->head = p;
        l->tail = p;
    }
    else{
        l->tail->next = p;
        l->tail = p;
    }
    return l;
}

LLIST deleteFromFront(LLIST l, int *value){
    if(isEmpty(l)){
        printf("List is empty\n");
        *value = -1;
        return l;
    }
    NODE *p = l->head;
    *value = p->data;
    l->head = p->next;
    free(p);
    if(l->head == NULL)     // if list is empty, make tail point to NULL
        l->tail = NULL;
    return l;
}

LLIST deleteFromEnd(LLIST l, int *value){
    if(isEmpty(l)){
        printf("List is empty\n");
        *value = -1;
        return l;
    }
    NODE *p = l->head;
    if(p->next == NULL){        // if list has only one node
        l->head = NULL;
        l->tail = NULL;
        *value = p->data;
        free(p);
        return l;
    }
    while(p->next->next != NULL)    //traverse to the second last node
        p = p->next;
    *value = p->next->data;
    free(p->next);                  //free the last node
    p->next = NULL;
    l->tail = p;
    return l;
}

LLIST deleteList(LLIST l, int key){
    if(isEmpty(l)){     // if list is empty, return 
        return l;
    }
    if(l->head->data == key){   // if the first node is the key, delete it
        NODE *p = l->head;
        l->head = p->next;
        free(p);
        return l;
    }
    NODE *last = l->head, *curr = l->head->next;
    while(curr != NULL){        // traverse the list until the key is found or the end of the list is reached
        if(curr->data == key){
            last->next = curr->next;
            free(curr);
            if(last->next == NULL)
                l->tail = last;
            return l;
        }
        last = curr;
        curr = curr->next;
    }
    return l;
}