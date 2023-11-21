#include <stdio.h>
#include <stdlib.h>

/* avlnode
maximum
height
createnode
rightrotate
leftrotate
getbalance
insert
minimum
delete
search
inordertraversal */

typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

int maximum(int a, int b) {
    return a > b ? a : b;
}

int height(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

AVLNode* createNode(int data) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

AVLNode* rightRotate(AVLNode* node) {
    AVLNode* leftofnode = node->left;
    AVLNode* rightofleft = leftofnode->right;

    leftofnode->right = node;
    node->left = rightofleft;

    leftofnode->height = (max(leftofnode->left, leftofnode->right)) + 1;
    node->right = (max(node->left, node->right)) + 1;

    return leftofnode;
}

AVLNode* leftRotate(AVLNode* node) {
    AVLNode* rightofnode = node->right;
    AVLNode* leftofright = rightofnode->left;

    rightofnode->left = node;
    node->right = leftofright;

    rightofnode->height = (max(rightofnode->left, rightofnode->right)) + 1;
    node->height = (max(node->left, node->right)) + 1;

    return rightofnode;
}

int getbalance(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return ((node->left->height) - (node->right->height));
}

AVLNode* insert(AVLNode* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }
    node->height = 1 + (height(node->left), height(node->right));
    int balance = getbalance(node);
    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }
    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

AVLNode* minimum(AVLNode* node) {
    AVLNode* current = node;
    while (current != NULL) {
        current = current->left;
    }
    return current;
}

AVLNode* delete(AVLNode* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete (root->left, data);
    } else if (data > root->data) {
        root->right = delete (root->right, data);
    } else {
        if (root->left == NULL || root->right == NULL) {
            AVLNode* temp = (root->left != NULL) ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            AVLNode* temp = minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
}

AVLNode* search(AVLNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

void inorder(AVLNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}