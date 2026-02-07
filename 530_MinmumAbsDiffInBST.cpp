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
        int minVal = INT_MAX;
        TreeNode* prev = nullptr;

        void Inorder(TreeNode* root)
        {
            if(root == nullptr) return;

            Inorder(root->left);
            if(prev) {
                minVal = min(minVal, (root->val - prev->val));
            }
            prev = root;
            Inorder(root->right);
        }

        int getMinimumDifference(TreeNode* root) 
        {
            Inorder(root);
            return minVal;
        }
};

int main()
{
    return 0;
}