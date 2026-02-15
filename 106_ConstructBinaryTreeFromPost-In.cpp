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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//  Iterative approach
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        vector<TreeNode*> stack;
        TreeNode* parent = nullptr;
        TreeNode* root = new TreeNode(post[n - 1]);

        stack.push_back(root);
        for(int i = n - 2, j = n - 1; i >= 0; i--) {
            TreeNode* node = new TreeNode(post[i]);

            if(stack.back()->val != in[j]) {
                stack.back()->right = node;
            } else {
                while(!stack.empty() && stack.back()->val == in[j]) {
                    parent = stack.back();
                    stack.pop_back();
                    j--;
                }
                parent->left = node;
            }
            stack.push_back(node);
        }
        return root;
    }
// Recursive approach
public:
    int idx = 0;
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& post, int start, int end)
    {
        if(start > end) return nullptr;

        int root_val = post[idx--];
        TreeNode* root = new TreeNode(root_val);
        int mid = mp[root_val];

        root->right = solve(post, mid + 1, end);
        root->left = solve(post, start, mid - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        for(int i = 0; i < in.size(); i++) {
            mp[in[i]] = i;
        }
        idx = post.size() - 1;
        return solve(post, 0, in.size()-1);
    }
};

int main()
{
    return 0;
}