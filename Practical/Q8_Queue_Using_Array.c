#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to add an element to the queue (enqueue)
void enqueue(int item) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    int item;
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        item = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("Dequeued: %d\n", item);
        return item;
    }
}

int main() {
    int choice, item;

    do {
        printf("\n+-------------------------------------+\n");
        printf("|        Choose Queue Operation       |\n");
        printf("+-------------------------------------+\n");
        printf("|1. Enqueue to Queue                  |\n");
        printf("|2. Dequeue from Queue                |\n");
        printf("|3. Check if the Queue is Empty       |\n");
        printf("|4. Check if the Queue is Full        |\n");
        printf("|5. Exit                              |\n");
        printf("+-------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != -1) {
                    printf("Dequeued element: %d\n", item);
                }
                break;
            case 3:
                if (front == -1) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                if ((rear + 1) % MAX_SIZE == front) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}