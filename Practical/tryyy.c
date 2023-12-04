#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Node{
    int data;
    Node* next;
}Node;

typedef struct AdjList{
    Node* head;
}AdjList;

typedef struct Graph{
    int numberofvertices;
    AdjList* array;
}Graph;

Graph* createGraph(int numberofvertices){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numberofvertices = numberofvertices;
    graph->array = (AdjList*)malloc(numberofvertices*sizeof(AdjList));

    for(int i = 0; i<numberofvertices; ++i){
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int source, int destination){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = destination;
    newnode->next= graph->array[source].head;
    graph->array[source].head = newnode;

    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = graph->array[destination].head;
    graph->array[destination].head = newnode;
}

void  DFS(Graph* graph, int vertex, bool visited){
    visited[vertex] = true;
    printf("%d",vertex);

    Node* adjacentnode = graph->array[vertex].head;
    while(adjacentnode!= NULL){
        if(!visited[adjacentnode->data]){
            DFS(graph, adjacentnode->data, visited);
        }
        adjacentnode = adjacentnode->next;
    }
}

void BFS(Graph* graph, int start){
    
}