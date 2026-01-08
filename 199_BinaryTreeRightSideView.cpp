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

    //  Using BFS technique
        vector<int> rightSideView(TreeNode* root) 
        {
            vector<int> res;
            if(!root) return res;

            queue<TreeNode*> queue;
            queue.push(root);

            while(!queue.empty())
            {   
                int levelSize = queue.size();
                res.push_back(queue.back()->val);

                for(int i = 0; i < levelSize; i++)
                {
                    TreeNode *node = queue.front();
                    queue.pop();

                    if(node->left) queue.push(node->left);
                    if(node->right) queue.push(node->right);
                }
            }
            return res;
        }
    
    // Using DFS technique
        void dfs(TreeNode* root, int level, vector<int>& res)
        {
            if(!root) return;

            if(res.size() == level) res.push_back(root->val);

            dfs(root->right,level+1,res);
            dfs(root->left, level+1, res);
        }

        vector<int> rightSideView1(TreeNode* root) 
        {
            vector<int> res;
            dfs(root,0,res);
            return res;
        }
};

int main()
{

    return 0;
}