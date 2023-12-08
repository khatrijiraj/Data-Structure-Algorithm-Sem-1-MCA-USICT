#include <stdio.h>
#include <stdlib.h>

// Define a typedef for struct Node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Doubly Linked List Functions

void insertAtBeginningDoubly(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtLocationDoubly(Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        insertAtBeginningDoubly(head, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* current = *head;
    int currentPos = 0;

    while (current != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
}

void insertAtEndDoubly(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void deleteAtBeginningDoubly(Node** head) {
    if (*head == NULL) {
        printf("Doubly Linked List is empty. Cannot delete.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteAtLocationDoubly(Node** head, int position) {
    if (*head == NULL) {
        printf("Doubly Linked List is empty. Cannot delete.\n");
        return;
    }

    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        deleteAtBeginningDoubly(head);
        return;
    }

    Node* current = *head;
    int currentPos = 0;

    while (current != NULL && currentPos < position) {
        current = current->next;
        currentPos++;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }

    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

void deleteAtEndDoubly(Node** head) {
    if (*head == NULL) {
        printf("Doubly Linked List is empty. Cannot delete.\n");
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(current);
}

void displayDoubly(Node* head) {
    Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("[%d] -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Circular Doubly Linked List Functions

void insertAtBeginningCircular(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtLocationCircular(Node** head, int data, int position) {
    if (*head == NULL) {
        printf("Circular Doubly Linked List is empty. Cannot insert.\n");
        return;
    }

    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        insertAtBeginningCircular(head, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* current = *head;
    int currentPos = 0;

    while (current != NULL && currentPos < position) {
        current = current->next;
        currentPos++;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
}

void insertAtEndCircular(Node** head, int data) {
    if (*head == NULL) {
        insertAtBeginningCircular(head, data);
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = *head;
    newNode->prev = (*head)->prev;
    (*head)->prev->next = newNode;
    (*head)->prev = newNode;
}

void deleteAtBeginningCircular(Node** head) {
    if (*head == NULL) {
        printf("Circular Doubly Linked List is empty. Cannot delete.\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* temp = *head;
    (*head)->next->prev = (*head)->prev;
    (*head)->prev->next = (*head)->next;
    *head = (*head)->next;
    free(temp);
}

void deleteAtLocationCircular(Node** head, int position) {
    if (*head == NULL) {
        printf("Circular Doubly Linked List is empty. Cannot delete.\n");
        return;
    }

    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        deleteAtBeginningCircular(head);
        return;
    }

    Node* current = *head;
    int currentPos = 0;

    while (current != NULL && currentPos < position) {
        current = current->next;
        currentPos++;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

void deleteAtEndCircular(Node** head) {
    if (*head == NULL) {
        printf("Circular Doubly Linked List is empty. Cannot delete.\n");
        return;
    }

    Node* current = *head;
    while (current->next != *head) {
        current = current->next;
    }

    if (current->prev != *head) {
        current->prev->next = *head;
        (*head)->prev = current->prev;
    } else {
        *head = NULL;
    }

    free(current);
}

void displayCircular(Node* head) {
    if (head == NULL) {
        printf("Circular Doubly Linked List is empty.\n");
        return;
    }

    Node* current = head;
    printf("Circular Linked List: ");
    do {
        printf("[%d] -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("Initial\n");
}

int main() {
    Node* doublyHead = NULL;
    Node* circularDoublyHead = NULL;

    int choice, data, position;

    while (1) {
        printf("\n+-------------------------------------+\n");
        printf("|           Main Menu                 |\n");
        printf("+-------------------------------------+\n");
        printf("|1. Doubly Linked List                |\n");
        printf("|2. Circular Doubly Linked List       |\n");
        printf("|3. Exit                              |\n");
        printf("+-------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                while (1) {
                    printf("\n+-------------------------------------+\n");
                    printf("|      Doubly Linked List             |\n");
                    printf("+-------------------------------------+\n");
                    printf("|1. Insertion                         |\n");
                    printf("|2. Deletion                          |\n");
                    printf("|3. Display                           |\n");
                    printf("|4. Back to Main Menu                 |\n");
                    printf("+-------------------------------------+\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to insert: ");
                            scanf("%d", &data);
                            printf("+-------------------------------------+\n");
                            printf("|      Doubly Insertion Menu          |\n");
                            printf("+-------------------------------------+\n");
                            printf("|1. Insert at Beginning               |\n");
                            printf("|2. Insert at Location                |\n");
                            printf("|3. Insert at End                     |\n");
                            printf("|4. Back to Doubly Linked List Menu   |\n");
                            printf("+-------------------------------------+\n");
                            printf("Enter your choice: ");
                            scanf("%d", &position);
                            if (position == 1) {
                                insertAtBeginningDoubly(&doublyHead, data);
                                displayDoubly(doublyHead);
                            } else if (position == 2) {
                                printf("Enter the position: ");
                                scanf("%d", &position);
                                insertAtLocationDoubly(&doublyHead, data, position);
                                displayDoubly(doublyHead);
                            } else if (position == 3) {
                                insertAtEndDoubly(&doublyHead, data);
                                displayDoubly(doublyHead);
                            } else if (position == 4) {
                                break;
                            } else {
                                printf("Invalid choice\n");
                            }
                            break;
                        case 2:
                            printf("+-------------------------------------+\n");
                            printf("|      Doubly Deletion Menu           |\n");
                            printf("+-------------------------------------+\n");
                            printf("|1. Delete at Beginning               |\n");
                            printf("|2. Delete at Location                |\n");
                            printf("|3. Delete at End                     |\n");
                            printf("|4. Back to Doubly Linked List Menu   |\n");
                            printf("+-------------------------------------+\n");
                            printf("Enter your choice: ");
                            scanf("%d", &position);
                            if (position == 1) {
                                deleteAtBeginningDoubly(&doublyHead);
                                displayDoubly(doublyHead);
                            } else if (position == 2) {
                                printf("Enter the position: ");
                                scanf("%d", &position);
                                deleteAtLocationDoubly(&doublyHead, position);
                                displayDoubly(doublyHead);
                            } else if (position == 3) {
                                deleteAtEndDoubly(&doublyHead);
                                displayDoubly(doublyHead);
                            } else if (position == 4) {
                                break;
                            } else {
                                printf("Invalid choice\n");
                            }
                            break;
                        case 3:
                            printf("Doubly Linked List: ");
                            displayDoubly(doublyHead);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                    if (choice == 4) {
                        break;
                    }
                }
                break;

            case 2:
                while (1) {
                    printf("\n+-------------------------------------+\n");
                    printf("| Circular Doubly Linked List         |\n");
                    printf("+-------------------------------------+\n");
                    printf("|1. Insertion                         |\n");
                    printf("|2. Deletion                          |\n");
                    printf("|3. Display                           |\n");
                    printf("|4. Back to Main Menu                 |\n");
                    printf("+-------------------------------------+\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to insert: ");
                            scanf("%d", &data);
                            printf("+-------------------------------------+\n");
                            printf("|      Circular Doubly Insertion Menu |\n");
                            printf("+-------------------------------------+\n");
                            printf("|1. Insert at Beginning               |\n");
                            printf("|2. Insert at Location                |\n");
                            printf("|3. Insert at End                     |\n");
                            printf("|4. Back to Circular Doubly Linked List Menu|\n");
                            printf("+-------------------------------------+\n");
                            printf("Enter your choice: ");
                            scanf("%d", &position);
                            if (position == 1) {
                                insertAtBeginningCircular(&circularDoublyHead, data);
                                displayCircular(circularDoublyHead);
                            } else if (position == 2) {
                                printf("Enter the position: ");
                                scanf("%d", &position);
                                insertAtLocationCircular(&circularDoublyHead, data, position);
                                displayCircular(circularDoublyHead);
                            } else if (position == 3) {
                                insertAtEndCircular(&circularDoublyHead, data);
                                displayCircular(circularDoublyHead);
                            } else if (position == 4) {
                                break;
                            } else {
                                printf("Invalid choice\n");
                            }
                            break;
                        case 2:
                            printf("+-------------------------------------+\n");
                            printf("| Circular Doubly Deletion Menu       |\n");
                            printf("+-------------------------------------+\n");
                            printf("|1. Delete at Beginning               |\n");
                            printf("|2. Delete at Location                |\n");
                            printf("|3. Delete at End                     |\n");
                            printf("|4. Back to Circular Doubly Linked List Menu|\n");
                            printf("+-------------------------------------+\n");
                            printf("Enter your choice: ");
                            scanf("%d", &position);
                            if (position == 1) {
                                deleteAtBeginningCircular(&circularDoublyHead);
                                displayCircular(circularDoublyHead);
                            } else if (position == 2) {
                                printf("Enter the position: ");
                                scanf("%d", &position);
                                deleteAtLocationCircular(&circularDoublyHead, position);
                                displayCircular(circularDoublyHead);
                            } else if (position == 3) {
                                deleteAtEndCircular(&circularDoublyHead);
                                displayCircular(circularDoublyHead);
                            } else if (position == 4) {
                                break;
                            } else {
                                printf("Invalid choice\n");
                            }
                            break;
                        case 3:
                            printf("Circular Doubly Linked List: ");
                            displayCircular(circularDoublyHead);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                    if (choice == 4) {
                        break;
                    }
                }
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}