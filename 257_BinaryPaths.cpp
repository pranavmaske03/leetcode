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
        void solve(TreeNode *root, vector<string>& res,string str)
        {
            if(root == nullptr) {
                return;
            }
            str += (str.empty()) ? to_string(root->val) : "->"+to_string(root->val);
            if(!root->left && !root->right) res.push_back(str);
            
            solve(root->left,res,str);
            solve(root->right,res,str);
        }

        vector<string> binaryTreePaths(TreeNode* root) 
        {
            vector<string> res;
            solve(root,res,"");
            return res;
        }
};

int main() 
{

}