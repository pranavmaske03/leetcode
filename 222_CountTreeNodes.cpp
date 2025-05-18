#include<iostream>

  // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}  // default constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // parametarised constructor
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // also parametarised constructor
};
  
 
class Solution 
{
    public:
        int countNodes(TreeNode* root) 
        {
            if(root == NULL) {
                return 0;
            }
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
};

int main()
{

    return 0;
}