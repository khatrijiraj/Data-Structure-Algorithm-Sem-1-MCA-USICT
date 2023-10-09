#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed!");
        exit(EXIT_FAILURE);
    }
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNodeAtStart(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* insertNodeAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        printf("Linked list is empty");
        return head;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* insertNodeAfter(Node* head, int data, int targetNodeValue) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        printf("Linked list is empty");
        return head;
    }
    Node* current = head;
    while (current != NULL) {
        if (current->value == targetNodeValue) {
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    }
    printf("Node with value %d not found in Linked list, Cannot insert after", targetNodeValue);
    return head;
}

Node* insertNodeAtPosition(Node* head, int data, int position) {
    if (position < 1) {
        printf("Position cannot be less than 1");
        return head;
    }
    Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    int currentPos = 1;
    while (currentPos = position - 1 && current != NULL) {
        current = current->next;
        currentPos++;
    }
    if (current == NULL) {
        printf("Invalid position, exceeds the length of Linked list");
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

Node* deleteNodeAtStart(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty");
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteNodeAtEnd(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty");
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

Node* deleteNodeByPosition(Node* head, int position) {
    if (position < 1) {
        printf("Position cannot be less than 1, cannot delete node");
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* current = head;
    int currentPos = 1;
    while (current != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
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

Node* deleteNodeByValue(Node* head, int targetValue) {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return head;
    }
    if (head->value == targetValue) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    } else {
        Node* current = head;
        Node* prev = NULL;
        while (current != NULL) {
            if (current->value == targetValue) {
                prev->next = current->next;
                free(current);
                return head;
            }
            prev = current;
            current = current->next;
        }
    }
    printf("Value %d not found in the list. Cannot delete.\n", value);
    return head;
}

int countNodes(Node* head) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        count = count++;
        current = current->next;
    }
    return count;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* save = NULL;

    while (current != NULL) {
        save = current->next;
        current->next == prev;
        prev = current;
        current = save;
    }
    return prev;
}

void FreeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("[%d] -> ", current->value);
        current = current->next;
    }
    printf("NULL");
}

typedef struct CircularNode {
    int data;
    CircularNode* next;
} CircularNode;

CircularNode* createCircularNode(int data) {
    CircularNode* newNode = (CircularNode*)malloc(sizeof(CircularNode));
    if (newNode == NULL) {
        printf("Memory allocationf failed");
        exit(EXIT_FAILURE);
    }
    newNode->value = data;
    newNode->next = newNode;
    return newNode;
}

CircularNode* insertNodeAtStartCircular(CircularNode* head, int data) {
    CircularNode* newNode = createCircularNode(data);
    
}

int main() {
    Node* head = NULL;
    return 0;
}