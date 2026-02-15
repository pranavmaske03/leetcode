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
        int DFS(TreeNode* root, int& maxSum)
        {
            if(root == nullptr) return 0;

            int left = max(0, DFS(root->left, maxSum));
            int right = max(0, DFS(root->right, maxSum));

            int currSum = root->val + left + right;
            maxSum = max(maxSum, currSum);
            return root->val + max(left, right);
        }

        int maxPathSum(TreeNode* root) 
        {
            int maxSum = INT_MIN;
            DFS(root, maxSum);
            return maxSum;
        }
};

int main()
{
    return 0;
}