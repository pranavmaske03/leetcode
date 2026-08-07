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
    void DFS(TreeNode* root, int& sum, bool isLeft) {
        if(!root)
            return;
        
        if(isLeft && !root->left && !root->right) 
            sum += root->val;
        
        DFS(root->left, sum, true);
        DFS(root->right, sum , false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int leftLeavesSum = 0;
        DFS(root, leftLeavesSum, false);
        return leftLeavesSum;
    }
};