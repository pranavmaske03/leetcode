#include<iostream>
#include<unordered_map>
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
        int count = 0;
        unordered_map<long long, int> mp;

        void dfs(TreeNode* root, long long currSum, int& targetSum)
        {
            if(root == nullptr) return;

            currSum += root->val;
            if(currSum == targetSum) count++;
            if(mp.count(currSum - targetSum)) {
                count += mp[currSum - targetSum];
            }
            mp[currSum]++;

            dfs(root->left,currSum,targetSum);
            dfs(root->right,currSum,targetSum);
            mp[currSum]--; // backtrack - sub the current sum count as we are going back to avoid wrong count;
        }

        int pathSum(TreeNode* root, int targetSum) 
        {
            if(!root) return count;
            dfs(root,0,targetSum);
            return count;
        }
};

int main()
{
    return 0;
}