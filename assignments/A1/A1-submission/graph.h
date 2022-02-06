#ifndef _GRAPH_H
#define _GRAPH_H
typedef struct _graph{
    int nodes, edges;
    int** adj;
}graph;

typedef graph *GRAPH;

typedef struct _graph_edge{
    int from, to, weight;
}graph_edge;

GRAPH readGraph(char *);  // Reads a graph from a file
void DFS(GRAPH);            //Prints nodes in DFS order
void BFS(GRAPH);            //Prints nodes in BFS order
void MST(GRAPH);            //Prints cost of MST
#endif