#include<iostream>

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
        bool isMirror(TreeNode *root1,TreeNode *root2) {

            if((root1 == nullptr && root2 != nullptr) || (root1 != nullptr && root2 == nullptr)) { 
                return false;
            }
            if(!root1 && !root2) {
                return true;
            }
            if(root1->val != root2->val) {
                return false;
            }

            return isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
        }

        bool isSymmetric(TreeNode* root) 
        {
            if(!root) return true;
            return isMirror(root->left,root->right);
        }
};

int main()
{

    return 0;
}