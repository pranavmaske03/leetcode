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
        void CollectLeafNodes(TreeNode *root, vector<int>& leaves) {
            if(!root) return;

            if(!root->left && !root->right) {
                leaves.push_back(root->val);
            }
            CollectLeafNodes(root->left,leaves);
            CollectLeafNodes(root->right,leaves);
        }

        bool leafSimilar(TreeNode* root1, TreeNode* root2) 
        {
            vector<int> leaves1,leaves2;

            CollectLeafNodes(root1,leaves1);
            CollectLeafNodes(root2,leaves2);
            
            return leaves1 == leaves2;
        }
};

int main()
{

    return 0;
}