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
        vector<vector<int>> levelOrder(TreeNode* root) 
        {
            vector<vector<int>> res;
            if(!root) return res;

            queue<TreeNode*> queue;
            int rear = 0,front = 0;
            queue.push(root);

            while(!queue.empty()) 
            {
                int level_size = queue.size();
                vector<int> row;

                for(int i = 0; i < level_size; i++)
                {
                    TreeNode* _tmp = queue.front();
                    queue.pop();

                    row.push_back(_tmp->val);
                    if(_tmp->left) queue.push(_tmp->left);
                    if(_tmp->right) queue.push(_tmp->right);
                }
                res.push_back(row);
            }
            return res;
        }
};

int main()
{

    return 0;
}