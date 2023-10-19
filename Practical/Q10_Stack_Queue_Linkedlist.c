#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

typedef struct {
    struct Node* top;
} Stack;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed to stack: %d\n", data);
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    printf("Popped from stack: %d\n", data);
    return data;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued to queue: %d\n", data);
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    printf("Dequeued from queue: %d\n", data);
    return data;
}

int main() {
    Stack* stack = createStack();
    Queue* queue = createQueue();
    int choice, data;

    while (1) {
        printf("\n+-------------------------------------+\n");
        printf("|  Choose Data Structure to Operate   |\n");
        printf("+-------------------------------------+\n");
        printf("|1. Stack                             |\n");
        printf("|2. Queue                             |\n");
        printf("|3. Exit                              |\n");
        printf("+-------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Stack
                do {
                    printf("\n+-------------------------------------+\n");
                    printf("|       Stack Operations              |\n");
                    printf("+-------------------------------------+\n");
                    printf("|1. Push to Stack                     |\n");
                    printf("|2. Pop from Stack                    |\n");
                    printf("|3. Return to Data Structure Menu     |\n");
                    printf("+-------------------------------------+\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to push: ");
                            scanf("%d", &data);
                            push(stack, data);
                            break;
                        case 2:
                            pop(stack);
                            break;
                        case 3:
                            printf("Returning to Data Structure Menu.\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (choice != 3);
                break;

            case 2:  // Queue
                do {
                    printf("\n+-------------------------------------+\n");
                    printf("|       Queue Operations              |\n");
                    printf("+-------------------------------------+\n");
                    printf("|1. Enqueue to Queue                  |\n");
                    printf("|2. Dequeue from Queue                |\n");
                    printf("|3. Return to Data Structure Menu     |\n");
                    printf("+-------------------------------------+\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to enqueue: ");
                            scanf("%d", &data);
                            enqueue(queue, data);
                            break;
                        case 2:
                            dequeue(queue);
                            break;
                        case 3:
                            printf("Returning to Data Structure Menu.\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (choice != 3);
                break;

            case 3:  // Exit
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}