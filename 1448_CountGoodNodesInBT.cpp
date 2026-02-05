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
        int DFS(TreeNode* root, int currMax)
        {
            if(root == nullptr) return 0;

            int count = 0;
            currMax = max(currMax, root->val);
            if(currMax == root->val) count++;

            count += DFS(root->left, currMax);
            count += DFS(root->right, currMax);

            return count;
        }

        int goodNodes(TreeNode* root) 
        {
            return DFS(root, root->val);
        }
};

int main()
{
    return 0;
}