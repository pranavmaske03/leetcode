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
            int helper(TreeNode *root) {
                if(root == nullptr) return 0;

                int leftHeight = helper(root->left);
                int rightHeight = helper(root->right);

                if(leftHeight == -1 || rightHeight == -1) return -1;
                return (abs(leftHeight - rightHeight) > 1 ? -1 : max(leftHeight, rightHeight) + 1 );
            }

            bool isBalanced(TreeNode* root) 
            {
                return helper(root) != -1;
            }
};

int main()
{

    return 0;
}