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
    bool check(vector<int>& nums) {
        int oddCount = 0;
        for(int& num : nums) {
            if(num%2 == 1) {
                oddCount++;
            }
        }
        return oddCount <= 1;
    }

    void DFS(TreeNode* root, vector<int>& nums, int& res) {
        if(root == nullptr)
            return;
        
        nums[root->val]++;
        if(!root->left && !root->right) {
            if(check(nums)) {
                res++;
            }
        }
        DFS(root->left, nums, res);
        DFS(root->right, nums, res);

        nums[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> nums(10, 0);
        int res = 0;

        DFS(root, nums, res);
        return res;
    }
};