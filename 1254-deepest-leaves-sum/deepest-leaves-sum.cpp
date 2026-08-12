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
    int leavesSum = 0;

    void DFS(TreeNode* root, int& maxDepth, int depth) {
        if(root == nullptr) 
            return;
        
        if(maxDepth < depth) {
            maxDepth = depth;
            leavesSum = 0;
        }
        if(maxDepth == depth) 
            leavesSum += root->val;

        DFS(root->left, maxDepth, depth + 1);
        DFS(root->right, maxDepth, depth + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = 0;
        DFS(root, maxDepth, 0);
        return leavesSum;
    }
};