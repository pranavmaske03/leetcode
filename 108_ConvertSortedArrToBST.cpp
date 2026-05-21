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
    TreeNode* solution(vector<int>& nums, int st, int end) { 
        if(st > end) {
            return NULL ;
        }
        //1.) take mid as root
        int mid = st + (end-st)/2 ;
        TreeNode* root = new TreeNode(nums[mid]) ;
        //2.) left elem. in nums => in left SubTree
        root->left = solution(nums, st, mid-1) ;
        //3.) right elem. in nums => in right SubTree
        root->right = solution(nums, mid+1, end) ;
       //very important to return the root
       return root ;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //solution func. 
        int n = nums.size() ;
        return solution(nums, 0, n-1) ; //as sortedArray... is a non-void func. , so return the func. call
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sol.sortedArrayToBST(nums);
    return 0;
}