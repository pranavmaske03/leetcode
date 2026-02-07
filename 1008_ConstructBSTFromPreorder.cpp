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
        TreeNode* bstFromPreorder(vector<int>& preorder) 
        {
            TreeNode* root = new TreeNode(preorder[0]);
            TreeNode* curr = nullptr;

            for(int i = 1; i < preorder.size(); i++) {
                curr = root;
                int val = preorder[i];

                while(curr) {
                    if(curr->val > val) {
                        if(!curr->left) {
                            curr->left = new TreeNode(val);
                            break;
                        }
                        curr = curr->left;
                    }
                    if(curr->val < val) {
                        if(!curr->right) {
                            curr->right = new TreeNode(val);
                            break;
                        }
                        curr = curr->right;
                    }
                }
            }
            return root;
        }
    //-------------------------------------------------------------------------
    //  Recursive approach
        TreeNode* insert(TreeNode* root, int val)
        {
            if(root == nullptr) return new TreeNode(val);

            if(root->val > val) {
                root->left = insert(root->left, val);
            } else {
                root->right = insert(root->right, val);
            }
            return root;
        }

        TreeNode* bstFromPreorder(vector<int>& preorder) {
            TreeNode* root = nullptr;

            for(int& val : preorder) {
                root = insert(root, val);
            }
            return root;
        }
};

int main()
{
    return 0;
}