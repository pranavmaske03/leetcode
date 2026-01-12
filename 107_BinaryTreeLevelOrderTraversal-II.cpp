#include<iostream>
#include<vector>
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
    //  Using BFS technique
        vector<vector<int>> levelOrderBottom(TreeNode* root) 
        {
            if(!root) return {}
            
            vector<vector<int>> res;
            queue<TreeNode*> queue;       
            queue.push(root);

            while(!queue.empty())
            {
                int levelSize = queue.size();
                vector<int> row(levelSize,0);

                for(int i = 0; i < levelSize; i++)
                {
                    TreeNode *node = queue.front();
                    queue.pop();
                    row[i] = node->val;

                    if(node->left) queue.push(node->left);
                    if(node->right) queue.push(node->right);
                }
                res.push_back(row);
            }
            reverse(res.begin(), res.end());
            return res;
        }
    //  Using DFS technique
        void solve(TreeNode* root, vector<vector<int>>& res,int level)
        {
            if(!root) return;

            if(level == res.size()) {
                res.push_back({});
            }
            res[level].push_back(root->val);
            solve(root->left,res,level+1);
            solve(root->right,res,level+1);
        }
        vector<vector<int>> levelOrderBottom(TreeNode* root) 
        {
            vector<vector<int>> res;
            int level = 0;
            solve(root,res,level);
            reverse(res.begin(), res.end());
            return res;
        }
};   

int main()
{
    return 0;
}
