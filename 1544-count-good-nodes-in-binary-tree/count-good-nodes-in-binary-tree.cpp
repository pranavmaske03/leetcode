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
    void DFS(TreeNode* root, int maxNode, int& count) {
        if(root == nullptr) 
            return;
        
        maxNode = max(maxNode, root->val);
        if(maxNode == root->val) {
            count++;
        }
        DFS(root->left, maxNode, count);
        DFS(root->right, maxNode, count);
    }

    int goodNodes(TreeNode* root) {
        int maxNode = INT_MIN;
        int goodNodes = 0;
        DFS(root, maxNode, goodNodes);
        return goodNodes;
    }
};