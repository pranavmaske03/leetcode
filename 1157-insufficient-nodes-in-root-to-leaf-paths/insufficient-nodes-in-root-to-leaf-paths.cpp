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
    TreeNode* DFS(TreeNode* root, int sum, int& limit) {
        if(!root)
            return nullptr;
        
        sum += root->val;
        if(!root->left && !root->right) {
            if(sum < limit)
                return nullptr;
            else
                return root;
        }
        root->left = DFS(root->left, sum, limit);
        root->right = DFS(root->right, sum, limit);

        if(!root->left && !root->right)
            return nullptr;

        return root;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int sum = 0;
        return DFS(root, sum, limit);
    }
};