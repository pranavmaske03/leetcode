#include<iostream>

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
    //  Using DFS technique
        bool isMirror(TreeNode *root1,TreeNode *root2) {

            if((root1 == nullptr && root2 != nullptr) || (root1 != nullptr && root2 == nullptr)) { 
                return false;
            }
            if(!root1 && !root2) {
                return true;
            }
            if(root1->val != root2->val) {
                return false;
            }

            return isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
        }

        bool isSymmetric(TreeNode* root) 
        {
            if(!root) return true;
            return isMirror(root->left,root->right);
        }
    // Using BFS technique
        bool isSymmetric(TreeNode* root) 
        {
            if (!root) return true;

            queue<TreeNode*> q;

            q.push(root->left);
            q.push(root->right);

            while (!q.empty())
            {
                TreeNode* left = q.front(); 
                q.pop();
                TreeNode* right = q.front(); 
                q.pop();

                if (!left && !right) continue;
                if (!left || !right) return false;
                
                if (left->val != right->val) {
                    return false;
                }

                q.push(left->left);
                q.push(right->right);

                q.push(left->right);
                q.push(right->left);
            }

            return true;
        }
};

int main()
{

    return 0;
}