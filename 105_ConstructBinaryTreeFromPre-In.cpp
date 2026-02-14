#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        vector<TreeNode*> stack;
        TreeNode* parent = nullptr;
        TreeNode* root = new TreeNode(pre[0]);

        stack.push_back(root);
        for (int i = 1, j = 0; i < pre.size(); i++) {
            TreeNode* node = new TreeNode(pre[i]);
            if (stack.back()->val != in[j]) {
                stack.back()->left = node;
            } else {
                while (!stack.empty() && stack.back()->val == in[j]) {
                    parent = stack.back();
                    stack.pop_back();
                    j++;
                }
                parent->right = node;
            }
            stack.push_back(node);
        }
        return root;
    }

// Recursive approach
public:
    int idx = 0;
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& preorder, int start, int end)
    {
        if(start > end) return nullptr;

        int root_val = preorder[idx++];
        TreeNode* root = new TreeNode(root_val);
        int mid = mp[root_val];

        root->left = solve(preorder, start, mid - 1);
        root->right = solve(preorder, mid + 1, end);
        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i = 0; i < in.size(); i++) {
            mp[in[i]] = i;
        }
        return solve(pre, 0, in.size() - 1);
    }
};

int main()
{
    return 0;
}