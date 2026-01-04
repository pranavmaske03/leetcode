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
void Preorder(struct TreeNode* root, int** arr, int* size, int* capacity)
{
    if(!root) return;

    if(*size == *capacity) {
        *capacity *= 2;
        *arr = (int*)realloc(*arr, sizeof(int) * (*capacity));
    }
    (*arr)[(*size)++] = root->val;
    Preorder(root->left,arr,size,capacity);
    Preorder(root->right,arr,size,capacity);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int size = 0;
    int capacity = 16;
    int *arr = malloc(capacity * sizeof(int));
    Preorder(root, &arr, &size, &capacity);
    *returnSize = size;
    return arr;
}

int main()
{
    return 0;
}