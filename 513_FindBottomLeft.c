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

void DFS(struct TreeNode* root,int depth, int *size, int *maxval)
{
    if(root == NULL) return;

    if((*size) == depth) {
        *maxval = root->val;
        (*size)++;
    }
    DFS(root->left, depth+1, size, maxval);
    DFS(root->right, depth+1, size, maxval);
}

int findBottomLeftValue(struct TreeNode* root) 
{
    int size = 0;
    int maxval = 0;
    DFS(root,0,&size,&maxval);
    return maxval;    
}

int main()
{
    return 0;
}