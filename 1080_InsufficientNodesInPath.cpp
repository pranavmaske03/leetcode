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
        // TreeNode* dfs(TreeNode* root, int limit, int currSum)
        // {
        //     if(root == nullptr) return root;

        //     currSum += root->val;
        //     if(!root->left && !root->right) {
        //         if(currSum < limit) return nullptr;
        //         else return root;
        //     }

        //     root->left = dfs(root->left, limit, currSum);
        //     root->right = dfs(root->right, limit, currSum);

        //     if(!root->left && !root->right) {
        //         return nullptr;
        //     }
        //     return root;
        // }

        TreeNode* sufficientSubset(TreeNode* root, int limit) 
        {
            if(root == nullptr) return root;
            if(!root->left && !root->right) {
                return root->val < limit ? nullptr : root;
            }
            
            root->left = sufficientSubset(root->left, limit - root->val);
            root->right = sufficientSubset(root->right, limit - root->val);

            if(!root->left && !root->right) return nullptr;
            return root;
        }
};

int main()
{
    return 0;
}