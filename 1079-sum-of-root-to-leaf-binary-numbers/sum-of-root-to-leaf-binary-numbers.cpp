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
        int binaryToNum(vector<bool>& binary) {
            int num = 0;
            for (bool bit : binary) {
                num = num * 2 + bit;
            }
            return num;
        }

        void DFS(TreeNode* root, vector<bool>& binary, int& sum) 
        {
            if(root == nullptr)
                return;

            binary.push_back(root->val);

            if(!root->left && !root->right) {
                sum += binaryToNum(binary);
            }
            DFS(root->left, binary, sum);
            DFS(root->right, binary, sum);
            
            binary.pop_back();
        }

        int sumRootToLeaf(TreeNode* root) 
        {
            if(root == nullptr) 
                return 0;

            vector<bool> binary;
            int sum = 0;

            DFS(root, binary, sum);  
            return sum;  
        }
};