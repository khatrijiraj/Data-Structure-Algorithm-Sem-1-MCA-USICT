#include <stdio.h>
#include <stdlib.h>

// Structure for singly linked list node
struct Node {
    int value;
    struct Node* next;
};

typedef struct Node Node;

// Function to create a new singly linked list node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of a singly linked list
Node* insertNodeAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to count the number of nodes in a singly linked list
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to display a singly linked list
void displayList(Node* head) {
    Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("[%d] -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to reverse a singly linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;  // The new head of the reversed list
}

// Function to free the memory of a singly linked list
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int data, nodeCount, operationChoice;

    while (1) {
        printf("\n+-------------------------------------+\n");
        printf("|           Main Menu                 |\n");
        printf("+-------------------------------------+\n");
        printf("|1. Insert Node                       |\n");
        printf("|2. Count Nodes                       |\n");
        printf("|3. Reverse List                      |\n");
        printf("|4. Display List                      |\n");
        printf("|5. Exit                              |\n");
        printf("+-------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &operationChoice);

        switch (operationChoice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertNodeAtEnd(head, data);
                printf("Node with value %d inserted.\n", data);
                break;
            case 2:
                nodeCount = countNodes(head);
                printf("Number of nodes in the list: %d\n", nodeCount);
                break;
            case 3:
                head = reverseList(head);
                printf("List reversed.\n");
                displayList(head);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                // Free the memory of the list before exiting
                freeList(head);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}