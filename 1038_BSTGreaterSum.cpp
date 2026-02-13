#include<iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs_inorder(TreeNode* root, int& sum)
    {
        if(root == nullptr) return;

        dfs_inorder(root->right, sum);
        sum += root->val;
        root->val = sum;
        dfs_inorder(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        dfs_inorder(root, sum);
        return root;
    }
};

int main()
{
    return 0;
}