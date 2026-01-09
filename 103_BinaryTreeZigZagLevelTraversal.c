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
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) 
{
    *returnSize = 0;
    if(!root) return NULL;

    int** res = (int**)calloc(2000, sizeof(int*));
    *returnColumnSizes = (int*)calloc(2000,sizeof(int));

    struct TreeNode* queue[2001] = {NULL};
    int rear = 0,front = 0;
    bool flag = true;
    queue[rear++] = root;

    while(front < rear)
    {
        int levelSize = rear - front;
        res[*returnSize] = (int*)calloc(levelSize,sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for(int i = 0; i < levelSize; i++)
        {
            struct TreeNode* _node = queue[front++];

            int idx = flag ? i : levelSize - i - 1;
            res[*returnSize][idx] = _node->val;

            if(_node->left) queue[rear++] = _node->left;
            if(_node->right) queue[rear++] = _node->right;
        }
        flag = !flag;
        (*returnSize)++;
    }
    return res;
}

int main()
{
    return 0;
}