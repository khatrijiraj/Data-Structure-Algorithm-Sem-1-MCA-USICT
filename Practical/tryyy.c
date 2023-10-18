#include <stdio.h>

#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if (rear = MAX - 1) {
        printf("OVERFLOW");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("Enqueued: %d", item);
    }
}

int dequeue() {
    int item;
    if (front == -1) {
        printf("UNDERFLOW");
        return -1;
    } else {
        item = queue[front];
        if (front == rear) {
            front = rear - 1;
        } else {
            front++;
        }
        printf("Dequeued: %d", item);
        return item;
    }
}