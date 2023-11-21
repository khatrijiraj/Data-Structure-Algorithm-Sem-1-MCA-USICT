/* Implement  traversals  on  Binary  Search  Tree  (using  stacks)
   -  Inorder, Preorder, Postorder) */
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure for a stack node
struct StackNode {
    struct Node* data;
    struct StackNode* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new stack node
struct StackNode* createStackNode(struct Node* node) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = node;
    stackNode->next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return !root;
}

// Function to push a node onto the stack
void push(struct StackNode** root, struct Node* node) {
    struct StackNode* stackNode = createStackNode(node);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to pop a node from the stack
struct Node* pop(struct StackNode** root) {
    if (isEmpty(*root))
        return NULL;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    struct Node* popped = temp->data;
    free(temp);
    return popped;
}

// Function to perform iterative inorder traversal
void iterativeInorder(struct Node* root) {
    struct Node* current = root;
    struct StackNode* stack = NULL;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

// Function to perform iterative preorder traversal
void iterativePreorder(struct Node* root) {
    if (root == NULL)
        return;

    struct StackNode* stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct Node* current = pop(&stack);
        printf("%d ", current->data);

        if (current->right)
            push(&stack, current->right);

        if (current->left)
            push(&stack, current->left);
    }
}

// Function to perform iterative postorder traversal
void iterativePostorder(struct Node* root) {
    if (root == NULL)
        return;

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;
    push(&stack1, root);

    while (!isEmpty(stack1)) {
        struct Node* current = pop(&stack1);
        push(&stack2, current);

        if (current->left)
            push(&stack1, current->left);

        if (current->right)
            push(&stack1, current->right);
    }

    while (!isEmpty(stack2)) {
        struct Node* current = pop(&stack2);
        printf("%d ", current->data);
    }
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
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
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    // Recursively search for the node to be deleted
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
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

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to display the main menu and get user choice
int displayMainMenu() {
    int choice;
    printf("\n+-------------------------------------+\n");
    printf("|      Main Menu                      |\n");
    printf("+-------------------------------------+\n");
    printf("|1. Binary Search Tree (BST) Operations|\n");
    printf("|2. Exit                              |\n");
    printf("+-------------------------------------+\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to display the BST menu and get user choice
int displayBSTMenu() {
    int choice;
    printf("\n+-------------------------------------+\n");
    printf("|     BST Operations Menu             |\n");
    printf("+-------------------------------------+\n");
    printf("|1. Insert                            |\n");
    printf("|2. Delete                            |\n");
    printf("|3. Search                            |\n");
    printf("|4. Inorder Traversal                 |\n");
    printf("|5. Preorder Traversal                |\n");
    printf("|6. Postorder Traversal               |\n");
    printf("|7. Back to Main Menu                 |\n");
    printf("+-------------------------------------+\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Driver program to test the program
int main() {
    struct Node* root = NULL;
    int mainChoice, bstChoice, value;

    do {
        mainChoice = displayMainMenu();

        switch (mainChoice) {
            case 1:
                do {
                    bstChoice = displayBSTMenu();

                    switch (bstChoice) {
                        case 1:
                            printf("Enter the value to insert into BST: ");
                            scanf("%d", &value);
                            root = insert(root, value);
                            break;

                        case 2:
                            printf("Enter the value to delete from BST: ");
                            scanf("%d", &value);
                            root = deleteNode(root, value);
                            break;

                        case 3:
                            printf("Enter the value to search in BST: ");
                            scanf("%d", &value);
                            if (search(root, value)) {
                                printf("%d is present in the BST.\n", value);
                            } else {
                                printf("%d is not present in the BST.\n", value);
                            }
                            break;

                        case 4:
                            printf("Inorder Traversal: ");
                            iterativeInorder(root);
                            printf("\n");
                            break;

                        case 5:
                            printf("Preorder Traversal: ");
                            iterativePreorder(root);
                            printf("\n");
                            break;

                        case 6:
                            printf("Postorder Traversal: ");
                            iterativePostorder(root);
                            printf("\n");
                            break;

                        case 7:
                            // Back to the main menu
                            break;

                        default:
                            printf("Invalid choice! Please enter a valid option.\n");
                    }
                } while (bstChoice != 7);
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