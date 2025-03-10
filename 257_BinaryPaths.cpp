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
class Solution {
public:
    vector<string>v;

    void check(TreeNode* root,string str){
        if(root->left == nullptr && root->right == nullptr){
            v.push_back(str);
            return;
        }
        if(root->left){
            if(str.back() != '>') str += "->";
            int n = to_string(root->left->val).size();
            str+= to_string(root->left->val);
            check(root->left,str);
            for(int i=0;i<n;i++)
                str.pop_back();
        } 
        if(root->right){
            if(str.back() != '>') str += "->";
            str+= to_string(root->right->val);
            check(root->right,str);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        check(root,to_string(root->val));
        return v;
    }
};

int main() 
{

}