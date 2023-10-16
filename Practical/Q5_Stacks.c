#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int TOS;  // TOS stands for Top Of Stack
} Stack;

void push(Stack *ST, int value) {
    if (ST->TOS == MAX_SIZE - 1) {
        printf("Stack overflow! Cannot push more elements.\n");
    } else {
        ST->items[++(ST->TOS)] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

void pop(Stack *ST) {
    if (ST->TOS == -1) {
        printf("Stack underflow! Cannot pop, the stack is empty.\n");
    } else {
        int value = ST->items[(ST->TOS)--];
        printf("Popped %d from the stack.\n", value);
    }
}

void peek(Stack *ST) {
    if (ST->TOS == -1) {
        printf("Stack is empty. Nothing to peek.\n");
    } else {
        int value = ST->items[ST->TOS];
        printf("Top element of the stack: %d\n", value);
    }
}

int main() {
    Stack st;
    st.TOS = -1;  // Initialize the TOS explicitly

    int choice, value;

    do {
        printf("\n+-------------------------------------+\n");
        printf("|        Choose Stack Operation       |\n");
        printf("+-------------------------------------+\n");
        printf("|1. Push to Stack                     |\n");
        printf("|2. Pop from Stack                    |\n");
        printf("|3. Peek at Stack                     |\n");
        printf("|4. Exit                              |\n");
        printf("+-------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&st, value);
                break;
            case 2:
                pop(&st);
                break;
            case 3:
                peek(&st);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}