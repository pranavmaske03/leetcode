#include<iostream>
#include<vector>
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
        vector<vector<int>>res;
        void dfs(TreeNode* root, int currSum, vector<int>& path, int& targetSum)
        {
            if(root == nullptr) return;

            currSum += root->val;
            path.push_back(root->val);
            if((!root->left && !root->right) && currSum == targetSum) {
                res.push_back(path);
            }
            dfs(root->left, currSum, path, targetSum);
            dfs(root->right, currSum, path, targetSum);

            currSum -= root->val;
            path.pop_back();
        }

        vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
        {
            vector<int> path;
            dfs(root,0, path, targetSum);
            return res;
        }
};

int main()
{
    return 0;
}