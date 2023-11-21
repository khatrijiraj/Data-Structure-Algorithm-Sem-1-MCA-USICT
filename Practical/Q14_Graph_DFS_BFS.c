/* Implement graph traversal (DFS & BFS) */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure for a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure for an adjacency list
struct AdjList {
    struct Node* head;
};

// Structure for a graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Function to create a new graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));

    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform Depth-First Search (DFS) traversal
void DFS(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* adjNode = graph->array[vertex].head;
    while (adjNode != NULL) {
        if (!visited[adjNode->data]) {
            DFS(graph, adjNode->data, visited);
        }
        adjNode = adjNode->next;
    }
}

// Function to perform Breadth-First Search (BFS) traversal
void BFS(struct Graph* graph, int start) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[start] = true;
    queue[++rear] = start;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        struct Node* adjNode = graph->array[currentVertex].head;
        while (adjNode != NULL) {
            int adjVertex = adjNode->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[++rear] = adjVertex;
            }
            adjNode = adjNode->next;
        }
    }
}

// Function to display the main menu and get user choice
int displayMainMenu() {
    int choice;
    printf("\n+-------------------------------------+\n");
    printf("|      Graph Operations Menu          |\n");
    printf("+-------------------------------------+\n");
    printf("|1. Add Edge                          |\n");
    printf("|2. Depth-First Search (DFS)           |\n");
    printf("|3. Breadth-First Search (BFS)         |\n");
    printf("|4. Exit                              |\n");
    printf("+-------------------------------------+\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Driver program to test graph operations
int main() {
    int numVertices, numEdges, i;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);
    int choice;
    do {
        choice = displayMainMenu();
        switch (choice) {
            case 1:
                printf("Enter the source and destination vertices for the edge (space-separated): ");
                int src, dest;
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;

            case 2:
                printf("Depth-First Search (DFS) traversal starting from vertex 0: ");
                bool visitedDFS[MAX_VERTICES] = {false};
                DFS(graph, 0, visitedDFS);
                printf("\n");
                break;

            case 3:
                printf("Breadth-First Search (BFS) traversal starting from vertex 0: ");
                BFS(graph, 0);
                printf("\n");
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}