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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> queue;
        int level = 0;

        queue.push(root);
        while(!queue.empty()) {
            int levelSize = queue.size();
            bool isEven = (level % 2 == 0);
            int prev = (isEven) ? INT_MIN : INT_MAX;
    
            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front(); queue.pop();

                if(isEven) {
                    if(node->val % 2 == 0 || node->val <= prev) 
                        return false;
                } else {
                    if(node->val % 2 == 1 || node->val >= prev)
                        return false;
                }
                prev = node->val;

                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
            level++;
        }
        return true;
    }
};