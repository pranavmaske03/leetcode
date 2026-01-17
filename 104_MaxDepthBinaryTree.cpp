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
    public:
        // using dfs traversal
        int maxDepth(TreeNode* root) 
        {
            if(root == nullptr) return 0;

            int leftHeight = maxDepth(root->left);
            int rightHeight = maxDepth(root->right);

            int max_depth = max(leftHeight,rightHeight);
            return max_depth + 1;
        }
        // using bfs traversal
        int maxDepth(TreeNode* root) 
        {
            if(root == nullptr) return 0;

            int depth = 0;
            queue<TreeNode*> queue;
            queue.push(root);

            while(!queue.empty())
            {
                int levelSize = queue.size();

                for(int i = 1; i <= levelSize; i++)
                {
                    TreeNode *node = queue.front();
                    queue.pop();

                    if(node->left) queue.push(node->left);
                    if(node->right) queue.push(node->right);
                }
                depth++;
            }
            return depth;
        }
};

int main()
{

    return 0;
}