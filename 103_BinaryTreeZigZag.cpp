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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
        {
            vector<vector<int>> res;
            if(!root) return res;

            queue<TreeNode*> queue;
            queue.push(root);
            bool flag = true;

            while(!queue.empty()) 
            {
                int levelSize = queue.size();
                vector<int> levelNodes(levelSize,0);

                for(int i = 0; i < levelSize; i++) {
                    TreeNode* node = queue.front();
                    queue.pop();
                    
                    int idx = flag ? i : levelSize - i - 1;
                    levelNodes[idx] = node->val;

                    if(node->left) queue.push(node->left);
                    if(node->right) queue.push(node->right);
                }
                flag = !flag;
                res.push_back(levelNodes);
            }
            return res;
        }
};

int main()
{

    return 0;
}