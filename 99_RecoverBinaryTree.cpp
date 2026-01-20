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
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        void dfs(TreeNode* curr, TreeNode*& prev)
        {
            if(curr == nullptr) return;

            dfs(curr->left,prev);
            if(prev && prev->val > curr->val) {
                if(!first) first = prev;
                second = curr;
            }
            prev = curr;
            dfs(curr->right, prev);
        }

        void recoverTree(TreeNode* root) 
        {
            TreeNode* prev = nullptr;
            dfs(root,prev);
            swap(first->val,second->val);    
        }
}; 

int main()
{
    return 0;
}