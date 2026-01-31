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
        TreeNode *lca;
        int maxDepth;

        int dfs(TreeNode *root, int depth)
        {
            if(root == nullptr) return depth - 1;

            maxDepth = max(depth,maxDepth);
            int left = dfs(root->left, depth + 1);
            int right = dfs(root->right, depth + 1);

            if(left == maxDepth && right == maxDepth) {
                lca = root;
            }
            return max(left,right);
        }
    public:
        TreeNode* subtreeWithAllDeepest(TreeNode* root) 
        {
            lca = nullptr;
            maxDepth = 0;
            dfs(root,0);
            return lca;
        }
};

int main()
{
    return 0;
}