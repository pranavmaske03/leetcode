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
    void inorder(TreeNode* root,  TreeNode*& newRoot, TreeNode*& prev) {
        if(root == nullptr)
            return;
        
        inorder(root->left, newRoot, prev);

        if(newRoot == nullptr) 
            newRoot = root;
        if(prev != nullptr) 
            prev->right = root;
            
        root->left = nullptr;
        prev = root;

        inorder(root->right, newRoot, prev);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = nullptr;
        TreeNode* prev = nullptr;

        inorder(root, newRoot, prev);
        return newRoot;
    }
};