#include<iostream>
using namespace std;

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
    struct Info {
        bool is_bst;
        int min_val;
        int max_val;
        int sum;
    };

    // Post-order traversal returning summary info for each subtree.
    Info dfs(TreeNode* node, int& global_max_sum) {
        if (node == nullptr) {
            // Empty tree is a valid BST with neutral min/max and zero sum.
            return { true, INT_MAX, INT_MIN, 0 };
        }

        Info left = dfs(node->left, global_max_sum);
        Info right = dfs(node->right, global_max_sum);

        // Current subtree is a BST when both sides are BSTs and node's value
        // is greater than left.max_val and less than right.min_val.
        if (left.is_bst && right.is_bst && left.max_val < node->val && node->val < right.min_val) {
            int curr_sum = left.sum + right.sum + node->val;
            global_max_sum = max(global_max_sum, curr_sum);
            return {
                true,
                min(left.min_val, node->val),
                max(right.max_val, node->val),
                curr_sum
            };
        }

        // Not a BST: mark as such. Other fields are not used by parent.
        return { false, 0, 0, 0 };
    }

    int maxSumBST(TreeNode* root) {
        int max_sum = 0;
        dfs(root, max_sum);
        return max_sum;
    }
};

int main() {
    return 0;
}