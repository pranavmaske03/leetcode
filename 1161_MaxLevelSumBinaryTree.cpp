#include<iostream>
#include<queue>
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
        int maxLevelSum(TreeNode* root) 
        {
            queue<TreeNode*> queue;
            queue.push(root);
            int maxSum = INT_MIN;
            int level = 0, ans = 0;

            while(!queue.empty()) 
            {
                int levelSize = queue.size();
                int currSum = 0;
    
                for(int i = 0; i < levelSize; i++) {
                    TreeNode* node = queue.front(); queue.pop();

                    currSum += node->val;
                    if(node->left) queue.push(node->left);
                    if(node->right) queue.push(node->right);
                }
                level++;

                if(maxSum < currSum) {
                    maxSum = currSum;
                    ans = level;
                }
            }
            return ans;
        }
};

int main()
{
    return 0;
}