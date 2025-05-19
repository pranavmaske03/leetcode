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
class Solution {
    public:
        int sumOfLeftLeaves(TreeNode* root, bool checkLeft = false) 
        {
            if(root == NULL) {
                return 0;
            }
            if(checkLeft && !root->left && !root->right) {
                return root->val;
            }

            int leftSum = sumOfLeftLeaves(root->left,true);
            int rightSum = sumOfLeftLeaves(root->right,false);
            return leftSum + rightSum;
        }
};

int main()
{

    return 0;
}