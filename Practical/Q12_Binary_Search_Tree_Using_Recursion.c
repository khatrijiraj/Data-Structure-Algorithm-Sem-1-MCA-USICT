/* Implement operations on Binary Search Tree (Insertion, Deletion, Search,
Traversals (using recursion)- Inorder, Preorder, Postorder). */
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Find the leftmost leaf node
    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a value from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    // Recursively search for the node to be deleted
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to display the menu and get user choice
int displayMenu() {
    int choice;
    printf("\n+-------------------------------------+\n");
    printf("|  Choose Data Structure to Operate   |\n");
    printf("+-------------------------------------+\n");
    printf("|1. Binary Search Tree (BST)          |\n");
    printf("|2. Exit                              |\n");
    printf("+-------------------------------------+\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to operate on Binary Search Tree
void operateOnBST() {
    struct Node* root = NULL;
    int value, choice;

    do {
        printf("\n+-------------------------------------+\n");
        printf("|    Operations on Binary Search Tree  |\n");
        printf("+-------------------------------------+\n");
        printf("|1. Insert                            |\n");
        printf("|2. Delete                            |\n");
        printf("|3. Inorder Traversal                 |\n");
        printf("|4. Preorder Traversal                |\n");
        printf("|5. Postorder Traversal               |\n");
        printf("|6. Back to Main Menu                 |\n");
        printf("+-------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 6:
                // Back to the main menu
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);
}

// Driver program
int main() {
    int mainChoice;

    do {
        mainChoice = displayMenu();

        switch (mainChoice) {
            case 1:
                operateOnBST();
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (mainChoice != 2);

    return 0;
}