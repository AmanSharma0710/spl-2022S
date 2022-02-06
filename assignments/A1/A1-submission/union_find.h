#ifndef _UNION_FIND_H
#define _UNION_FIND_H
typedef struct _union_find_node{
    int data;
    struct _union_find_node *parent;
    int size;
}union_find_node;

typedef union_find_node *NODE_PTR;

typedef struct _union_find{
    NODE_PTR *nodes;
    int size;
}union_find;

typedef union_find *UNION_FIND;

UNION_FIND createUF(int);       //create storage for union find data structure
UNION_FIND makeSetUF(UNION_FIND, int, int *); //make a set with a single element and return index of the element
NODE_PTR findUF(UNION_FIND, int); //find the root of the set containing the element
void unionUF(UNION_FIND, int, int); //merges the sets containing the elements at the given indices
#endif