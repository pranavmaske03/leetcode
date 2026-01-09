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
class Solution 
{ 
    public:
        void dfs(TreeNode* root, int depth, int &size, int &leftval) 
        {
            if(!root) return;

            if(size == depth) {
                leftval = root->val;
                size++;
            }
            dfs(root->left, depth+1, size, leftval);
            dfs(root->right, depth+1, size, leftval);
        }

        int findBottomLeftValue(TreeNode* root) 
        {
            int size = 0;
            int leftval = 0;
            dfs(root,0,size,leftval);
            return leftval;
        }

    //  Using BFS
        int findBottomLeftValue(TreeNode* root) 
        {
            if(!root) return 0;

            int leftMost = 0;
            queue<TreeNode*> queue;
            queue.push(root);

            while(!queue.empty())
            {
                int levelSize = queue.size();
                leftMost = queue.front()->val;

                for(int i = 0; i < levelSize; i++)
                {
                    TreeNode *node = queue.front();
                    queue.pop();

                    if(node->left) queue.push(node->left);
                    if(node->right) queue.push(node->right);
                }
            }
            return leftMost;
        }
};

int main()
{

    return 0;
}