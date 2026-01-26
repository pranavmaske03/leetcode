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
        int pseudoCount = 0;
        
        void DFS(TreeNode* root, vector<int>& parity, int oddCount)
        {
            if(root == nullptr) return;

            parity[root->val] ^= 1;
            if(parity[root->val] == 1) {
                oddCount++;
            } else {
                oddCount--;
            }

            if(!root->left && !root->right && oddCount < 2) {
                pseudoCount++;
            }
            DFS(root->left, parity, oddCount);
            DFS(root->right, parity, oddCount);

            parity[root->val] ^= 1; // backtracking the parity again to maintain correct count;
        }

        int pseudoPalindromicPaths (TreeNode* root) 
        {
            if(root == nullptr) return 0;
            vector<int> parity(10,0);
            DFS(root, parity, 0);
            return pseudoCount;
        }
};

int main()
{

    return 0;
}
