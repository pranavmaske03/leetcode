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
        TreeNode* prev = nullptr;
        bool isValidBST(TreeNode* root) 
        {
            if(root == nullptr) return true;

            bool left = isValidBST(root->left);

            if(prev && prev->val >= root->val) return false;
            prev = root;

            bool right = isValidBST(root->right);
            return left && right;
        }   
};

int main()
{
    return 0;
}