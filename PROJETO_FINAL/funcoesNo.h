#ifndef FUNCOESNO_H
#define FUNCOESNO_H

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int value);
struct TreeNode* insert(struct TreeNode* root, int value);
int search(struct TreeNode* root, int value);
void inorderTraversal(struct TreeNode* root);
void preorderTraversal(struct TreeNode* root);
void postorderTraversal(struct TreeNode* root);
struct TreeNode* minValueNode(struct TreeNode* node);
struct TreeNode* deleteNode(struct TreeNode* root, int value);
int minValue(struct TreeNode* root);
int maxValue(struct TreeNode* root);
void freeTree(struct TreeNode* root);
#endif 
