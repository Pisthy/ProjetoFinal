#include "funcoesNo.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (node != NULL) {
        node->key = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }

    if (value < root->key) {
        root->left = insert(root->left, value);
    } else if (value > root->key) {
        root->right = insert(root->right, value);
    }

    return root;
}

int search(struct TreeNode* root, int value) {
    if (root == NULL) {
        return 0;
    }

    if (root->key == value) {
        return 1;
    } else if (value < root->key) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}


void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->key) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->key) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int minValue(struct TreeNode* root) {
    struct TreeNode* current = root;

    
    while (current->left != NULL) {
        current = current->left;
    }

    return current->key;
}

int maxValue(struct TreeNode* root) {
    struct TreeNode* current = root;

    
    while (current->right != NULL) {
        current = current->right;
    }

    return current->key;
}
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}