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
    void DFS(TreeNode* root, int& minLen, int depth) {
        if(root == nullptr)
            return;
        
        if(!root->left && !root->right) {
            minLen = min(minLen, depth);
        }

        DFS(root->left, minLen, depth + 1);
        DFS(root->right, minLen, depth + 1);
    }

    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
            
        int minLen = INT_MAX;
        DFS(root, minLen, 1);
        return minLen;
    }
};