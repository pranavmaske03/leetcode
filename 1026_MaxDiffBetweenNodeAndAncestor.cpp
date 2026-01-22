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
        void dfs(TreeNode* root, int& maxDiff, int minVal, int maxVal)
        {
            if(root == nullptr) return;

            int currDiff = max(abs(root->val - maxVal), abs(root->val - minVal));
            maxDiff =  max(maxDiff,currDiff);
      
            maxVal = max(maxVal,root->val);
            minVal = min(minVal,root->val);

            //maxDiff = max(maxDiff,(maxVal - minVal));
            dfs(root->left, maxDiff, minVal, maxVal);
            dfs(root->right, maxDiff, minVal, maxVal);
        }

        int maxAncestorDiff(TreeNode* root) 
        {
            int maxDiff = INT_MIN;
            dfs(root,maxDiff,root->val,root->val);
            return maxDiff;
        }
};

int main()
{

    return 0;
}