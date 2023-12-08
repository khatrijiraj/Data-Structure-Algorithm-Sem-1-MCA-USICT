#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph structure
typedef struct {
    int vertices;
    int **adjMatrix;
} Graph;

// Stack structure for DFS
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// Queue structure for BFS
typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to initialize a stack
Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int vertex) {
    stack->data[++stack->top] = vertex;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    return stack->data[stack->top--];
}

// Function to initialize a queue
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (int *)malloc(capacity * sizeof(int));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue *queue) {
    return queue->front == -1;
}

// Function to enqueue an element
void enqueue(Queue *queue, int vertex) {
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->data[queue->rear] = vertex;
}

// Function to dequeue an element
int dequeue(Queue *queue) {
    int vertex = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return vertex;
}

// Function to create a graph with the given number of vertices
Graph *createGraph(int vertices) {
    int i, j;
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int start, int end) {
    graph->adjMatrix[start][end] = 1;
    graph->adjMatrix[end][start] = 1;
}
// Function for Depth-First Search (DFS)
void DFS(Graph *graph, int start) {
    Stack *stack = createStack(graph->vertices);
    int visited[MAX_VERTICES] = {0};

    push(stack, start);
    visited[start] = 1;

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(stack, i);
                visited[i] = 1;
            }
        }
    }

    free(stack);
}

// Function for Breadth-First Search (BFS)
void BFS(Graph *graph, int start) {
    Queue *queue = createQueue(graph->vertices);
    int visited[MAX_VERTICES] = {0};

    enqueue(queue, start);
    visited[start] = 1;

    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }

    free(queue);
}

void displayMenu() {
    printf("\n+-------------------------------------+\n");
    printf("|      Graph Operations Menu          |\n");
    printf("+-------------------------------------+\n");
    printf("|1. Depth-First Search (DFS)          |\n");
    printf("|2. Breadth-First Search (BFS)        |\n");
    printf("|3. Exit                              |\n");
    printf("+-------------------------------------+\n");
}

int main() {
    int vertices, edges, i;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph *graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: start end):\n");
    for (i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(graph, start, end);
    }

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &vertices);
                printf("DFS Traversal: ");
                DFS(graph, vertices);
                printf("\n");
                break;

            case 2:
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &vertices);
                printf("BFS Traversal: ");
                BFS(graph, vertices);
                printf("\n");
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}