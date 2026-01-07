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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) 
{   
    *returnSize = 0;
    if(!root) return NULL; 

    int** arr =  (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    struct TreeNode* queue[20001] = {NULL};
    int rear = 0,front = 0;
    queue[rear++] = root;

    while(front < rear) 
    {
        int diff = rear - front;
        arr[*returnSize] = (int*)malloc(diff * sizeof(int));
        (*returnColumnSizes)[*returnSize] = diff;

        for(int i = 0; i < diff; i++) {
            struct TreeNode* _curr = queue[front++];
            arr[*returnSize][i] = _curr->val;

            if(_curr->left) {
                queue[rear++] = _curr->left;
            }
            if(_curr->right) {
                queue[rear++] = _curr->right;
            }
        }
        (*returnSize)++;
    }
    return arr;
}

int main()
{
    return 0;
}