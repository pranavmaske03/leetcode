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
class Solution 
{
    public:
        int dfs(TreeNode* root, int k, int& count)
        {
            if(root == nullptr) return -1;

            int left = dfs(root->left, k, count);

            if(left != -1) return left;
            if(++count == k) return root->val;
            
            return dfs(root->right, k, count);
        }

        int kthSmallest(TreeNode* root, int k) 
        {
            int count = 0;
            return dfs(root,k,count);
        }
};

int main()
{
    return 0;
}