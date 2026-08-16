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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {
            int levelSize = queue.size();
            vector<int> row(levelSize, 0);

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front(); queue.pop();
                row[i] = node->val;
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
            res.push_back(row);
        }

        return res;
    }
};