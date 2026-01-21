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
        bool dfs(TreeNode* root, int& targetSum, int currSum)
        {
            if(root == nullptr) return false;

            currSum += root->val;
            if((currSum == targetSum) && (!root->left && !root->right)) return true;

            return dfs(root->left, targetSum, currSum) || dfs(root->right, targetSum, currSum);
        }

        bool hasPathSum(TreeNode* root, int targetSum) 
        {
            return dfs(root,targetSum,0);
        }

        // Another optimized approach
        bool hasPathSum(TreeNode* root, int targetSum) 
        {
            if(root == nullptr) return false;

            if(!root->left && !root->right && targetSum - root->val == 0) return true;

            if(hasPathSum(root->left, targetSum - root->val)) {
                return true;
            }
            if(hasPathSum(root->right, targetSum - root->val)) {
                return true;
            }
            return false;
        }
};

int main()
{

    return 0;
}