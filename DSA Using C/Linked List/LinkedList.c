#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at a specified location in the linked list
void insertAtLocation(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0 || *head == NULL) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int currentPos = 0;

    while (current != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to delete a node at the beginning of the linked list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at a specified location in the linked list
void deleteAtLocation(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    int currentPos = 0;

    while (current != NULL && currentPos < position) {
        prev = current;
        current = current->next;
        currentPos++;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

// Function to delete a node at the end of the linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to print the circular linked list
void printCircularList(struct Node* head) {
    if (head == NULL) {
        printf("Circular list is empty\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    struct Node* head = NULL;          // For singly linked list
    struct Node* circularHead = NULL;  // For circular singly linked list

    int choice, data, position;

    while (1) {
        printf("\nLinked List Menu\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Location\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Location\n");
        printf("6. Delete at End\n");
        printf("7. Print Singly Linked List\n");
        printf("8. Print Circular Linked List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtLocation(&head, data, position);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtLocation(&head, position);
                break;
            case 6:
                deleteAtEnd(&head);
                break;
            case 7:
                printf("Singly Linked List: ");
                printList(head);
                break;
            case 8:
                printf("Circular Linked List: ");
                printCircularList(circularHead);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}