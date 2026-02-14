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
    // Iterative approach
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode*> stack;

        stack.push_back(new TreeNode(pre[0]));
        for (int i = 1, j = 0; i < pre.size(); i++) {
            TreeNode* node = new TreeNode(pre[i]);
            while (stack.back()->val == post[j]) {
                stack.pop_back();
                j++;
            }

            if (stack.back()->left == nullptr)
                stack.back()->left = node;
            else
                stack.back()->right = node;

            stack.push_back(node);
        }
        cout << stack.size() << endl;
        return stack[0];
    }

    // recursive approach
    int preIdx = 0, posIdx = 0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[preIdx++]);
        if (root->val != post[posIdx]) {
            root->left = constructFromPrePost(pre, post);
        }
        if (root->val != post[posIdx]) {
            root->right = constructFromPrePost(pre, post);
        }
        posIdx++;
        return root;
    }
};

int main()
{
    return 0;
}