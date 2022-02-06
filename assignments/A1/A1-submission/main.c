#include<stdio.h>
#include<stdlib.h>
#include<llist.h>
#include<stack.h>
#include<queue.h>
#include<union_find.h>
#include<graph.h>

#define MAX_LIMIT 20
//Increase this value if you want to enter a long file name. 
//Added to prevent buffer overflow

int main(){
    printf("Enter file name containing the graph: ");
    //Take the input and parse it
    char FName[MAX_LIMIT];
    fgets(FName, MAX_LIMIT, stdin);
    int endline = 0;
    for(int i=0; i<MAX_LIMIT; i++){
        if(FName[i]=='\n'){
            endline = 1;
            FName[i]='\0';
            break;
        }
    }
    if(!endline){
        printf("File name was too long. Increase buffer size in main.c to accomodate it.\n");
        return 0;
    }
    
    GRAPH G = readGraph(FName);
    DFS(G);
    BFS(G);
    MST(G);
    return 0;
}