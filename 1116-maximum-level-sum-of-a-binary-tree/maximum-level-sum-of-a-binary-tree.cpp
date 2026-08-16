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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> queue;
        int res = 0, level = 0;
        int levelSum = 0, maxSum = INT_MIN;

        queue.push(root);
        while(!queue.empty()) {
            int currSum = 0;
            int levelSize = queue.size(); 

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front(); queue.pop();

                currSum += node->val;
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
            level++;
            if(maxSum < currSum) {
                maxSum = currSum;
                res = level;
            }
        }
        return res;
    }
};