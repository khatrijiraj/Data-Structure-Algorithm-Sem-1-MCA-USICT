/* Implement AVL tree */
#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

struct AVLNode* newNode(int data) {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct AVLNode* rightRotate(struct AVLNode* node) {
    struct AVLNode* leftofnode = node->left;
    struct AVLNode* rightofleft = leftofnode->right;

    leftofnode->right = node;
    node->left = rightofleft;

    node->height = max(height(node->left), height(node->right)) + 1;
    leftofnode->height = max(height(leftofnode->left), height(leftofnode->right)) + 1;

    return leftofnode;
}

struct AVLNode* leftRotate(struct AVLNode* node) {
    struct AVLNode* rightofnode = node->right;
    struct AVLNode* leftofright = rightofnode->left;

    rightofnode->left = node;
    node->right = leftofright;

    node->height = max(height(node->left), height(node->right)) + 1;
    rightofnode->height = max(height(rightofnode->left), height(rightofnode->right)) + 1;

    return rightofnode;
}

int getBalance(struct AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

struct AVLNode* insert(struct AVLNode* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) {
        return rightRotate(node);
    }
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0) {
        return leftRotate(node);
    }

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct AVLNode* minValueNode(struct AVLNode* node) {
    struct AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct AVLNode* deleteNode(struct AVLNode* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct AVLNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct AVLNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct AVLNode* temp = minValueNode(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct AVLNode* search(struct AVLNode* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

void inorder(struct AVLNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void displayMenu() {
    printf("\n+-----------------------------------+\n");
    printf("|        AVL Tree Operations        |\n");
    printf("+-----------------------------------+\n");
    printf("| 1. Insert a key                   |\n");
    printf("| 2. Delete a key                   |\n");
    printf("| 3. Search for a key               |\n");
    printf("| 4. Inorder Traversal              |\n");
    printf("| 5. Exit                           |\n");
    printf("+-----------------------------------+\n");
    printf("Enter your choice: ");
}

int main() {
    struct AVLNode* root = NULL;
    int choice, key;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;

            case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL)
                    printf("Key %d found in the AVL tree.\n", key);
                else
                    printf("Key %d not found in the AVL tree.\n", key);
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
