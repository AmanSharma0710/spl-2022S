#include<stdio.h>
#include<stdlib.h>
#include <union_find.h>

int main(){
    UNION_FIND uf = createUF(10);
    int index1, index2;
    makeSetUF(uf, 1, &index1);
    makeSetUF(uf, 2, &index2);
    unionUF(uf, index1, index2);
    makeSetUF(uf, 3, &index1);
    makeSetUF(uf, 4, &index2);
    unionUF(uf, index1, index2);
    makeSetUF(uf, 5, &index1);
    unionUF(uf, index1, index2);
    for(int i=0; i<uf->size; i++){
        if(uf->nodes[i] != NULL){
            printf("%d ", uf->nodes[i]->data);
            printf("Parent: %d\n", findUF(uf, i)->data);
        }
    }
    unionUF(uf, 0, 2);
    for(int i=0; i<uf->size; i++){
        if(uf->nodes[i] != NULL){
            printf("%d ", uf->nodes[i]->data);
            printf("Parent: %d\n", findUF(uf, i)->data);
        }
    }
    return 0;
}