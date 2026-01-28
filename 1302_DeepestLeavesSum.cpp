#include<iostream>
#include<queue>
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
    //  DFS technique
        int leavesSum = 0;
        void DFS(TreeNode* root, int& maxDepth, int depth)
        {
            if(root == nullptr) return;
            if(maxDepth < depth) {
                maxDepth = depth;
                leavesSum = 0;
            }
            if(maxDepth == depth) leavesSum += root->val;

            DFS(root->left, maxDepth, depth + 1);
            DFS(root->right, maxDepth, depth + 1);
        }

        int deepestLeavesSum(TreeNode* root) 
        {
            // BFS  technique
            queue<TreeNode*> q;
            q.push(root);
            
            while(!q.empty()) {
                int levelSize = q.size();
                leavesSum = 0;

                for(int i = 0; i < levelSize; i++) {
                    TreeNode* node = q.front(); q.pop();
                    
                    leavesSum += node->val;
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            return leavesSum;

        // int maxDepth = 0;
        // DFS(root,maxDepth, 0);
        // return leavesSum;
        }
};

int main()
{
    return 0;
}