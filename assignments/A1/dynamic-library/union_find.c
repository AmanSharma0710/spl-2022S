#include <stdio.h>
#include <stdlib.h>
#include "union_find.h"

UNION_FIND createUF(int n){
    UNION_FIND uf = (UNION_FIND)malloc(sizeof(struct _union_find));
    uf->nodes = (NODE_PTR *)malloc(sizeof(NODE_PTR)*n);
    uf->size = n;
    return uf;
}

UNION_FIND makeSetUF(UNION_FIND uf, int data, int *index){
    NODE_PTR node = (NODE_PTR)malloc(sizeof(struct _union_find_node));
    node->data = data;
    node->parent = NULL;
    node->size = 1;
    for(int i=0; i<uf->size; i++){
        //we add the node at the first empty index
        if(uf->nodes[i] == NULL){
            uf->nodes[i] = node;
            *index = i;
            return uf;
        }
        //if the node is not null, check if the data is the same
        if(uf->nodes[i]->data == data){
            printf("%d is already present\n", data);
            *index = i;
            return uf;
        }
    }
    printf("Cannot add more elements to the union find data structure\n");
    *index = -1;
    return uf;
}

NODE_PTR findUF(UNION_FIND uf, int index){
    NODE_PTR id = uf->nodes[index];
    while(id->parent != NULL){
        id = id->parent;
    }
    return id;
}

void unionUF(UNION_FIND uf, int index1, int index2){
    NODE_PTR node1 = findUF(uf, index1);
    NODE_PTR node2 = findUF(uf, index2);
    if(node1 == node2){
        printf("Entered nodes are already in the same set\n");
        return;
    }
    //we merge the smaller set into the larger set and update the size of the larger set
    if(node1->size < node2->size){
        node1->parent = node2;
        node2->size += node1->size;
    }
    else{
        node2->parent = node1;
        node1->size += node2->size;
    }
    return;
}