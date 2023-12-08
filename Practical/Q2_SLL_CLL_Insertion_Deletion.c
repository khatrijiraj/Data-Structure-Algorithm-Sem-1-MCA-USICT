#include <stdio.h>
#include <stdlib.h>

// Structure for singly linked list node
struct Node {
    int value;
    struct Node* next;
};

typedef struct Node Node;

// Structure for circular singly linked list node
struct CircularNode {
    int value;
    struct CircularNode* next;
};

typedef struct CircularNode CircularNode;

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

// Function to create a new circular singly linked list node
CircularNode* createCircularNode(int data) {
    CircularNode* newNode = (CircularNode*)malloc(sizeof(CircularNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = data;
    newNode->next = newNode;  // Circular link to itself
    return newNode;
}

// Function to insert a node at the beginning of a singly linked list
Node* insertNodeAtStart(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
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

// Function to insert a node after a specific value in a singly linked list
Node* insertNodeAfter(Node* head, int data, int targetData) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        printf("The list is empty. Cannot insert after.\n");
        return head;
    }

    Node* current = head;
    while (current != NULL) {
        if (current->value == targetData) {
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    }

    printf("Target node with value %d not found. Cannot insert after.\n", targetData);
    return head;
}

// Function to insert a node at a specific position in a singly linked list
Node* insertNodeAtPosition(Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return head;
    }
    Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    int currentPosition = 1;
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        printf("Invalid position. Position exceeds the length of the list.\n");
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the first node of a singly linked list
Node* deleteNodeAtStart(Node* head) {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node of a singly linked list
Node* deleteNodeAtEnd(Node* head) {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete a node by position in a singly linked list
Node* deleteNodeByPosition(Node* head, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return head;
    }
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return head;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* current = head;
    int currentPosition = 1;
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL || current->next == NULL) {
        printf("Invalid position. Position exceeds the length of the list.\n");
        return head;
    }
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Function to delete a node by value in a singly linked list
Node* deleteNodeByValue(Node* head, int value) {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return head;
    }

    if (head->value == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->value == value) {
            prev->next = current->next;
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }

    printf("Value %d not found in the list. Cannot delete.\n", value);
    return head;
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

// Function to insert a node at the beginning of a circular singly linked list
CircularNode* insertNodeAtStartCircular(CircularNode* head, int data) {
    CircularNode* newNode = createCircularNode(data);
    if (head == NULL) {
        newNode->next = newNode;  // Point to itself to make it circular
        return newNode;
    }
    newNode->next = head->next;
    head->next = newNode;
    return head;
}

// Function to insert a node at the end of a circular singly linked list
CircularNode* insertNodeAtEndCircular(CircularNode* head, int data) {
    CircularNode* newNode = createCircularNode(data);
    if (head == NULL) {
        newNode->next = newNode;  // Point to itself to make it circular
        return newNode;
    }
    newNode->next = head->next;
    head->next = newNode;
    return newNode;  // Return the new last node
}

// Function to insert a node after a specific value in a circular singly linked list
CircularNode* insertNodeAfterCircular(CircularNode* head, int data, int targetData) {
    CircularNode* newNode = createCircularNode(data);

    if (head == NULL) {
        printf("The circular list is empty. Cannot insert after.\n");
        return head;
    }

    CircularNode* current = head;

    do {
        if (current->value == targetData) {
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    } while (current != head);

    printf("Target node with value %d not found. Cannot insert after.\n", targetData);
    return head;
}

// Function to delete a node by value in a circular singly linked list
CircularNode* deleteNodeByValueCircular(CircularNode* head, int value) {
    if (head == NULL) {
        printf("The circular list is empty. Cannot delete.\n");
        return head;
    }

    CircularNode* current = head;
    CircularNode* prev = NULL;

    do {
        if (current->value == value) {
            if (prev == NULL) {
                if (current->next == current) {
                    free(current);
                    return NULL;  // List becomes empty
                }
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    printf("Value not found in the circular list.\n");
    return head;
}

void displayCircularList(CircularNode* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }
    CircularNode* current = head;
    printf("Circular Linked List: ");
    do {
        printf("[%d] -> ", current->value);
        current = current->next;
    } while (current != head);
    printf("Initial\n");
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

// Function to free the memory of a circular singly linked list
void freeCircularList(CircularNode* head) {
    if (head == NULL) {
        return;
    }
    CircularNode* current = head->next;
    while (current != head) {
        CircularNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);  // Free the head node
}

int main() {
    Node* head = NULL;
    CircularNode* circularHead = NULL;
    int data, linkedListChoice, operationChoice, specificOperationChoice, targetData;

    while (1) {
        printf("\n+-------------------------------------+\n");
        printf("|             Main Menu               |\n");
        printf("+-------------------------------------+\n");
        printf("|1. Singly Linked List                |\n");
        printf("|2. Circular Singly Linked List       |\n");
        printf("|3. Exit                              |\n");
        printf("+-------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &linkedListChoice);

        if (linkedListChoice < 1 || linkedListChoice > 3) {
            printf("\nInvalid choice. Please try again.\n");
            continue;  // Continue the loop to re-prompt for input
        } else {
            switch (linkedListChoice) {
                case 1:
                    while (1) {
                        printf("\n\t+-------------------------------------+\n");
                        printf("\t|          Choose Operation           |\n");
                        printf("\t+-------------------------------------+\n");
                        printf("\t|1. Insertion                         |\n");
                        printf("\t|2. Deletion                          |\n");
                        printf("\t|3. Display                           |\n");
                        printf("\t|4. Navigate to previous menu         |\n");
                        printf("\t+-------------------------------------+\n");
                        printf("\tEnter your choice: ");
                        scanf(" %d", &operationChoice);

                        switch (operationChoice) {
                            case 1:
                                while (1) {
                                    printf("\n\t\t+-------------------------------------+\n");
                                    printf("\t\t|         Singly Insertion Menu       |\n");
                                    printf("\t\t+-------------------------------------+\n");
                                    printf("\t\t|1. Insert at beginning               |\n");
                                    printf("\t\t|2. Insert at end                     |\n");
                                    printf("\t\t|3. Insert at position                |\n");
                                    printf("\t\t|4. Insert after a node by value      |\n");
                                    printf("\t\t|5. Navigate to previous menu         |\n");
                                    printf("\t\t+-------------------------------------+\n");
                                    printf("\t\tEnter your choice: ");
                                    scanf(" %d", &specificOperationChoice);

                                    switch (specificOperationChoice) {
                                        case 1:
                                            printf("\t\tEnter the data to insert: ");
                                            scanf("%d", &data);
                                            head = insertNodeAtStart(head, data);
                                            printf("\t\tNode with value %d inserted at the beginning.\n", data);
                                            displayList(head);
                                            break;
                                        case 2:
                                            printf("\t\tEnter the data to insert: ");
                                            scanf("%d", &data);
                                            head = insertNodeAtEnd(head, data);
                                            printf("\t\tNode with value %d inserted at the end.\n", data);
                                            displayList(head);
                                            break;
                                        case 3:
                                            printf("\t\tEnter the data to insert: ");
                                            scanf("%d", &data);
                                            printf("\t\tEnter the position to insert: ");
                                            scanf("%d", &targetData);
                                            head = insertNodeAtPosition(head, data, targetData);
                                            displayList(head);
                                            break;
                                        case 4:
                                            printf("\t\tEnter the data to insert: ");
                                            scanf("%d", &data);
                                            printf("\t\tEnter the value after which to insert: ");
                                            scanf("%d", &targetData);
                                            head = insertNodeAfter(head, data, targetData);
                                            displayList(head);
                                            break;
                                        case 5:
                                            break;
                                        default:
                                            printf("\t\tInvalid choice. Please try again.\n");
                                            break;
                                    }
                                    if (specificOperationChoice == 5) {
                                        break;  // Exit the inner while loop
                                    }
                                }
                                break;
                            case 2:
                                while (1) {
                                    printf("\n\t\t+-------------------------------------+\n");
                                    printf("\t\t|         Singly Deletion Menu        |\n");
                                    printf("\t\t+-------------------------------------+\n");
                                    printf("\t\t|1. Delete at beginning               |\n");
                                    printf("\t\t|2. Delete at end                     |\n");
                                    printf("\t\t|3. Delete at position                |\n");
                                    printf("\t\t|4. Delete a node by value            |\n");
                                    printf("\t\t|5. Navigate to previous menu         |\n");
                                    printf("\t\t+-------------------------------------+\n");
                                    printf("\t\tEnter your choice: ");
                                    scanf(" %d", &specificOperationChoice);

                                    switch (specificOperationChoice) {
                                        case 1:
                                            head = deleteNodeAtStart(head);
                                            displayList(head);
                                            break;
                                        case 2:
                                            head = deleteNodeAtEnd(head);
                                            displayList(head);
                                            break;
                                        case 3:
                                            printf("\t\tEnter the position to delete: ");
                                            scanf("%d", &targetData);
                                            head = deleteNodeByPosition(head, targetData);
                                            displayList(head);
                                            break;
                                        case 4:
                                            printf("\t\tEnter the value to delete: ");
                                            scanf("%d", &data);
                                            head = deleteNodeByValue(head, data);
                                            displayList(head);
                                            break;
                                        case 5:
                                            break;
                                        default:
                                            printf("\t\tInvalid choice. Please try again.\n");
                                            break;
                                    }
                                    if (specificOperationChoice == 5) {
                                        break;  // Exit the inner while loop
                                    }
                                }
                                break;
                            case 3:
                                displayList(head);
                                break;
                            case 4:
                                break;
                            default:
                                printf("\t\tInvalid choice. Please try again.\n");
                                break;
                        }
                        if (operationChoice == 4) {
                            break;  // Exit the inner while loop
                        }
                    }
                    break;

                case 2:
                    while (1) {
                        printf("\n\t+-------------------------------------+\n");
                        printf("\t|    Circular Singly Linked List      |\n");
                        printf("\t+-------------------------------------+\n");
                        printf("\t|1. Insertion                         |\n");
                        printf("\t|2. Deletion                          |\n");
                        printf("\t|3. Display                           |\n");
                        printf("\t|4. Navigate to previous menu         |\n");
                        printf("\t+-------------------------------------+\n");
                        printf("\tEnter your choice: ");
                        scanf(" %d", &operationChoice);

                        switch (operationChoice) {
                            case 1:
                                while (1) {
                                    printf("\n\t\t+-------------------------------------+\n");
                                    printf("\t\t|      Circular Insertion Menu        |\n");
                                    printf("\t\t+-------------------------------------+\n");
                                    printf("\t\t|1. Insert at beginning               |\n");
                                    printf("\t\t|2. Insert at end                     |\n");
                                    printf("\t\t|3. Insert after a node by value      |\n");
                                    printf("\t\t|4. Navigate to previous menu         |\n");
                                    printf("\t\t+-------------------------------------+\n");
                                    printf("\t\tEnter your choice: ");
                                    scanf(" %d", &specificOperationChoice);

                                    switch (specificOperationChoice) {
                                        case 1:
                                            printf("\t\tEnter the data to insert: ");
                                            scanf("%d", &data);
                                            circularHead = insertNodeAtStartCircular(circularHead, data);
                                            printf("\t\tNode with value %d inserted at the beginning.\n", data);
                                            displayCircularList(circularHead);
                                            break;
                                        case 2:
                                            printf("\t\tEnter the data to insert: ");
                                            scanf("%d", &data);
                                            circularHead = insertNodeAtEndCircular(circularHead, data);
                                            printf("\t\tNode with value %d inserted at the end.\n", data);
                                            displayCircularList(circularHead);
                                            break;
                                        case 3:
                                            printf("\t\tEnter the data to insert: ");
                                            scanf("%d", &data);
                                            printf("\t\tEnter the value after which to insert: ");
                                            scanf("%d", &targetData);
                                            circularHead = insertNodeAfterCircular(circularHead, data, targetData);
                                            displayCircularList(circularHead);
                                            break;
                                        case 4:
                                            break;
                                        default:
                                            printf("\t\tInvalid choice. Please try again.\n");
                                            break;
                                    }
                                    if (specificOperationChoice == 4) {
                                        break;  // Exit the inner while loop
                                    }
                                }
                                break;
                            case 2:
                                while (1) {
                                    printf("\n\t\t+-------------------------------------+\n");
                                    printf("\t\t|      Circular Deletion Menu         |\n");
                                    printf("\t\t+-------------------------------------+\n");
                                    printf("\t\t|1. Delete a node by value            |\n");
                                    printf("\t\t|2. Navigate to previous menu         |\n");
                                    printf("\t\t+-------------------------------------+\n");
                                    printf("\t\tEnter your choice: ");
                                    scanf(" %d", &specificOperationChoice);

                                    switch (specificOperationChoice) {
                                        case 1:
                                            printf("\t\tEnter the value to delete: ");
                                            scanf("%d", &data);
                                            circularHead = deleteNodeByValueCircular(circularHead, data);
                                            displayCircularList(circularHead);
                                            break;
                                        case 2:
                                            break;
                                        default:
                                            printf("\t\tInvalid choice. Please try again.\n");
                                            break;
                                    }
                                    if (specificOperationChoice == 2) {
                                        break;  // Exit the inner while loop
                                    }
                                }
                                break;
                            case 3:
                                displayCircularList(circularHead);
                                break;
                            case 4:
                                break;
                            default:
                                printf("\t\tInvalid choice. Please try again.\n");
                                break;
                        }
                        if (operationChoice == 4) {
                            break;  // Exit the inner while loop
                        }
                    }
                    break;

                case 3:
                    printf("Exiting the program. Goodbye!\n");
                    // Free the memory of both lists before exiting
                    freeList(head);
                    freeCircularList(circularHead);

                    exit(EXIT_SUCCESS);
                    break;

                default:
                    printf("\nInvalid choice. Please try again.\n");
                    break;
            }
        }
    }

    return 0;
}
