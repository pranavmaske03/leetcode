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
class Solution 
{
    private:
        TreeNode* lca = nullptr;
        int maxDepth = 0;

    public:_
        int dfs(TreeNode *root, int depth)
        {
            maxDepth = max(depth,maxDepth);
            if(root == nullptr) return depth;

            int left = dfs(root->left, depth + 1);
            int right = dfs(root->right, depth + 1);

            if(left == maxDepth && right == maxDepth) {
                lca = root;
            }
            return max(left, right);
        }

        TreeNode* lcaDeepestLeaves(TreeNode* root) 
        {
            dfs(root,0);
            return lca;
        }
};

int main()
{

    return 0;
}