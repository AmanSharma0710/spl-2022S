#include <stdio.h>
#include <stdlib.h>
#include <llist.h>
#include <stack.h>
#include <queue.h>
#include <union_find.h>
#include <graph.h>

GRAPH readGraph(char *FName){
    FILE *file = fopen(FName, "r");         // Open file
    if(file == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    GRAPH G;                                //Allocate memory for graph
    G = (GRAPH)malloc(sizeof(struct _graph));
    int n, m;
    fscanf(file, "%d %d", &n, &m);          //Read number of vertices and edges
    G->nodes = n;
    G->edges = m;
    G->adj = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){             //Allocate memory for adjacency matrix
        G->adj[i] = (int *)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            G->adj[i][j] = 0;
        }
    }
    int x, y, weight;
    for(int i = 0; i < m; i++){             //Read edges and weights
        fscanf(file, "%d %d %d", &x, &y, &weight);
        G->adj[x][y] = weight;
        G->adj[y][x] = weight;
    }
    fclose(file);
    return G;
}


void DFS(GRAPH G){
    int *visited = (int *)malloc(G->nodes * sizeof(int));
    for(int i = 0; i < G->nodes; i++){
        visited[i] = 0;
    }
    STACK S = createStack();
    printf("DFS:\n");       //We visit and print node in depth first order
    for(int i = 0; i < G->nodes; i++){
        if(visited[i] == 0){            //For all unvisited nodes
            S = push(S, i);             //Push node onto stack and mark as visited
            while(!isEmpty(S)){        //While stack is not empty, we keep adding unvisited nodes
                int u;
                S = pop(S, &u);
                if(!visited[u]){
                    visited[u] = 1;
                    printf("%d ", u);
                    for(int j = G->nodes-1; j >= 0; j--){
                        if(G->adj[u][j] != 0 && visited[j] == 0){
                            S = push(S, j);
                        }
                    }
                }
            }
        }
    }
    printf("\n");
    free(visited);
    return;
}

void BFS(GRAPH G){
    int *visited = (int *)malloc(G->nodes * sizeof(int));
    for(int i = 0; i < G->nodes; i++){
        visited[i] = 0;
    }
    QUEUE Q = createQueue();
    printf("BFS:\n");       //We visit and print node in breadth first order
    for(int i = 0; i < G->nodes; i++){
        if(visited[i] == 0){            //For all unvisited nodes
            Q = enqueue(Q, i);          //Enqueue node onto queue and mark as visited
            visited[i] = 1;
            while(!isEmpty(Q)){        //While queue is not empty, we keep adding unvisited nodes
                int u;
                Q = dequeue(Q, &u);
                printf("%d ", u);
                for(int j = 0; j < G->nodes; j++){
                    if(G->adj[u][j] != 0 && visited[j] == 0){
                        Q = enqueue(Q, j);
                        visited[j] = 1;
                    }
                }
            }
        }
    }
    printf("\n");
    free(visited);
    return;
}

void mergeEdges(graph_edge *edges, graph_edge *temp, int l, int middle, int r){       //Helper function for mergeSort
    int i = l;
    int j = middle + 1;
    int k = l;
    while((i <= middle) && (j <= r)){
        if(edges[i].weight <= edges[j].weight){
            temp[k].from = edges[i].from;
            temp[k].to = edges[i].to;
            temp[k].weight = edges[i].weight;
            i++; k++;
        }
        else{
            temp[k].from = edges[j].from;
            temp[k].to = edges[j].to;
            temp[k].weight = edges[j].weight;
            j++; k++;
        }
    }
    while(i <= middle){
        temp[k].from = edges[i].from;
        temp[k].to = edges[i].to;
        temp[k].weight = edges[i].weight;
        i++; k++;
    }
    while(j <= r){
        temp[k].from = edges[j].from;
        temp[k].to = edges[j].to;
        temp[k].weight = edges[j].weight;
        j++; k++;
    }
    for(int i = l; i <= r; i++){
        edges[i].from = temp[i].from;
        edges[i].to = temp[i].to;
        edges[i].weight = temp[i].weight;
    }
    return;
}

void sortEdges(graph_edge *edges, graph_edge *temp, int l, int r){        //We use merge sort to sort the edges in O(nlogn) time and in ascending order
    if(l<r){
        int middle = l + (r-l)/2;
        sortEdges(edges, temp, l, middle);
        sortEdges(edges, temp, middle+1, r);
        mergeEdges(edges, temp, l, middle, r);
    }
    return;
}

void MST(GRAPH G){
    graph_edge *edges = (graph_edge *)malloc(G->edges * sizeof(graph_edge));
    graph_edge *temp = (graph_edge *)malloc(G->edges * sizeof(graph_edge));
    int index = 0, n = G->nodes;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(G->adj[i][j] != 0){
                edges[index].from = i;
                edges[index].to = j;
                edges[index].weight = G->adj[i][j];
                index++;
            }
        }
    }
    sortEdges(edges, temp, 0, G->edges-1);        //We obtain the edges in ascending order
    //Now we can apply Kruskal's algorithm to find the minimum spanning tree and print it in increasing order of weights
    UNION_FIND uf = createUF(n);
    int *indexInUF = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        uf = makeSetUF(uf, i, &indexInUF[i]);
    }
    printf("MST:\nEdges:\n");
    int weight = 0;
    for(int i=0; i<G->edges; i++){
        int u = edges[i].from;
        int v = edges[i].to;
        if(findUF(uf, indexInUF[u]) != findUF(uf, indexInUF[v])){
            printf("%d %d %d\n", u, v, edges[i].weight);
            unionUF(uf, indexInUF[u], indexInUF[v]);
            weight += edges[i].weight;
        }
    }
    printf("Weight: %d\n", weight);     //Print the weight of the MST
    free(edges);
    free(temp);
    free(indexInUF);
    return;
}