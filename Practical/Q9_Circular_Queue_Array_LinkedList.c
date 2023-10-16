#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Array-based circular queue variables
int circularQueue[MAX_SIZE];
int front_array = -1;
int rear_array = -1;

// Linked list-based circular queue variables
struct Node* front_list = NULL;
struct Node* rear_list = NULL;

void enqueueArray(int data) {
    if (front_array == -1) {
        front_array = rear_array = 0;
    } else if ((rear_array + 1) % MAX_SIZE == front_array) {
        printf("Array-based Queue is full. Cannot enqueue.\n");
        return;
    } else {
        rear_array = (rear_array + 1) % MAX_SIZE;
    }
    circularQueue[rear_array] = data;
    printf("Enqueued to Array-based Queue: %d\n", data);
}

int dequeueArray() {
    if (front_array == -1) {
        printf("Array-based Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = circularQueue[front_array];
    if (front_array == rear_array) {
        front_array = rear_array = -1;
    } else {
        front_array = (front_array + 1) % MAX_SIZE;
    }
    printf("Dequeued from Array-based Queue: %d\n", data);
    return data;
}

void enqueueList(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (front_list == NULL) {
        front_list = rear_list = newNode;
    } else {
        rear_list->next = newNode;
        rear_list = newNode;
    }
    printf("Enqueued to Linked List-based Queue: %d\n", data);
}

int dequeueList() {
    if (front_list == NULL) {
        printf("Linked List-based Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    struct Node* temp = front_list;
    int data = temp->data;
    front_list = front_list->next;
    free(temp);
    if (front_list == NULL) {
        rear_list = NULL;
    }
    printf("Dequeued from Linked List-based Queue: %d\n", data);
    return data;
}

int main() {
    int choice, data;

    while (1) { // Loop for main menu
        printf("\n+-------------------------------------+\n");
        printf("|      Choose Queue Implementation    |\n");
        printf("+-------------------------------------+\n");
        printf("|1. Array-based Circular Queue        |\n");
        printf("|2. Linked List-based Circular Queue  |\n");
        printf("|3. Exit                              |\n");
        printf("+-------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Array-based Circular Queue
                do {
                    printf("\n+--------------------------------------+\n");
                    printf("|  Array-based Circular Queue Options  |\n");
                    printf("+--------------------------------------+\n");
                    printf("|1. Enqueue                            |\n");
                    printf("|2. Dequeue                            |\n");
                    printf("|3. Return to Main Menu                |\n");
                    printf("+--------------------------------------+\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to enqueue: ");
                            scanf("%d", &data);
                            enqueueArray(data);
                            break;
                        case 2:
                            dequeueArray();
                            break;
                        case 3:
                            printf("Returning to Main Menu.\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (choice != 3);
                break;
            case 2: // Linked List-based Circular Queue
                do {
                    printf("\n+--------------------------------------+\n");
                    printf("|Linked List-based Circular Queue Opt. |\n");
                    printf("+--------------------------------------+\n");
                    printf("|1. Enqueue                            |\n");
                    printf("|2. Dequeue                            |\n");
                    printf("|3. Return to Main Menu                |\n");
                    printf("+--------------------------------------+\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to enqueue: ");
                            scanf("%d", &data);
                            enqueueList(data);
                            break;
                        case 2:
                            dequeueList();
                            break;
                        case 3:
                            printf("Returning to Main Menu.\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (choice != 3);
                break;
            case 3: // Exit
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}