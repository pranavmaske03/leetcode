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
        void DFS(TreeNode* root, int& sum)
        {
            if(root == nullptr) return;

            if(root->val%2 == 0) {
                if(root->left) {
                    if(root->left->left) {
                        sum += root->left->left->val;
                    }
                    if(root->left->right) {
                        sum += root->left->right->val;
                    }
                }
                if(root->right) {
                    if(root->right) {
                        if(root->right->left) {
                            sum += root->right->left->val;
                        }
                        if(root->right->right) {
                            sum += root->right->right->val;
                        }
                    }
                }
            }
            DFS(root->left, sum);
            DFS(root->right, sum);
        }

        int sumEvenGrandparent(TreeNode* root) 
        {
            int sum = 0;
            DFS(root,sum);
            return sum;
        }
};

// 2nd approach
class Solution 
{
    public:
        void DFS(TreeNode* current, TreeNode* parent, TreeNode* grandparent, int& sum) 
        {
            if(current == nullptr) return;

            if(grandparent && grandparent->val % 2 == 0) {
                sum += current->val;
            }
            
            DFS(current->left, current, parent, sum);
            DFS(current->right, current, parent, sum);
        }
        int sumEvenGrandparent(TreeNode* root) 
        {
            int sum = 0;
            DFS(root,nullptr,nullptr,sum);
            return sum;
        }
};

int main()
{
    return 0;
}