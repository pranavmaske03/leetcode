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

void Postorder(struct TreeNode* root, int** arr, int* size, int* capacity)
{
    if(!root) return;

    Postorder(root->left,arr,size,capacity);
    Postorder(root->right,arr,size,capacity);
    if(*size == *capacity) {
        *capacity *= 2;
        *arr = realloc(*arr,sizeof(int) * (*capacity));
    }
    (*arr)[(*size)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int size = 0;
    int capacity = 16;
    int *arr = malloc(capacity * sizeof(int));
    Postorder(root, &arr, &size, &capacity);
    *returnSize = size;
    return arr;    
}

int main()
{

    return 0;
}