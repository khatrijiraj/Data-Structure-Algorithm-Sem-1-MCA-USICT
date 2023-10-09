#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAfterNodeByValue(Node*& head, int data, int target) {
    Node* newNode = new Node(data);
    Node* cursor = head;
    while (cursor != NULL) {
        if (cursor->data == target) {
            newNode->next = cursor->next;
            cursor->next = newNode;
        }
        cursor = cursor->next;
    }
    cout << "Node with value " << target << " not found!" << endl;
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    Node* cursor = head;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = newNode;
}

void display(Node*& head) {
    Node* cursor = head;
    cout << "Linked list: ";
    while (cursor != NULL) {
        cout << "[" << cursor->data << "]"
             << " -> ";
        cursor = cursor->next;
    }
    cout << "NULL" << endl;
}



int main() {
    Node* n1 = new Node(1);
    insertAtHead(n1, 2);
    insertAtEnd(n1, 3);
    insertAfterNodeByValue(n1, 4, 2);
    insertAfterNodeByValue(n1, 5, 2);
    display(n1);
    return 0;
}