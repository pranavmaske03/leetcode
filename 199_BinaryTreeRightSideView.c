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

// USING BFS TECHNIQUE
int* rightSideView(struct TreeNode* root, int* returnSize) 
{   
    int* res = (int*)calloc(100, sizeof(int));
    *returnSize = 0;
    if(!root) return NULL;

    struct TreeNode *queue[101] = {NULL};
    int rear = 0,front = 0,idx = 0;
    queue[rear++] = root;

    while(front < rear)
    {
        int level = rear - front;
        res[idx++] = queue[rear - 1]->val;

        for(int i = 0; i < level; i++)
        {
            struct TreeNode *node = queue[front++];

            if(node->left) queue[rear++] = node->left;
            if(node->right) queue[rear++] = node->right;
        }
    }
    *returnSize = idx;
    return res;
}

int main()
{
    return 0;
}