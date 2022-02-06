#ifndef _LLIST_H
#define _LLIST_H
typedef struct _node{
    int data;
    struct _node *next;
}NODE;

typedef struct _llist{
    NODE *head;
    NODE *tail;
}llist;                     // Linked List

typedef llist *LLIST;       //LLIST is a pointer to llist

LLIST createList();                 //create a new list
int isEmpty(LLIST);                 //check if list is empty(return 1 if empty, 0 if not)
int searchList(LLIST, int);         //search for a value in the list(returns 1 if found, 0 if not)
LLIST insertAtFront(LLIST, int);    //insert a value at the front of the list
LLIST insertAtEnd(LLIST, int);      //insert a value at the end of the list
LLIST deleteFromFront(LLIST, int*);  //delete a value from the front of the list
LLIST deleteFromEnd(LLIST, int*);    //delete a value from the end of the list
LLIST deleteList(LLIST, int);       //delete first instance of a value from the list if it exists
#endif