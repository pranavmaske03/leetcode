#include<iostream>
#include<string>
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
        void DFS(TreeNode* root, string& str, string currStr)
        {
            if(root == nullptr) return;

            currStr = string(1, root->val + 'a') + currStr;
            if(!root->left && !root->right) {
                str = (str.empty()) ? currStr : min(str, currStr);
            }
            DFS(root->left, str, currStr);
            DFS(root->right, str, currStr);
        }

        string smallestFromLeaf(TreeNode* root) 
        {
            string str = "";
            DFS(root,str,"");
            return str;
        }
};

int main()
{
    return 0;
}