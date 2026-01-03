#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
void Inorder(struct TreeNode* root, int** arr, int* size, int* capacity)
{
    if (!root) return;

    Inorder(root->left, arr, size, capacity);

    // Resize array if needed
    if (*size == *capacity) {
        *capacity *= 2;
        *arr = (int*)realloc(*arr, sizeof(int) * (*capacity));
    }
    (*arr)[(*size)++] = root->val;

    Inorder(root->right, arr, size, capacity);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int capacity = 16;
    int size = 0;
    int* result = (int*)malloc(sizeof(int) * capacity);

    Inorder(root, &result, &size, &capacity);

    *returnSize = size;
    return result;
}

int main()
{
    return 0;
}