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
    private:
        int NOT_COVERED = 0;
        int HAS_CAMERA = 1;
        int COVERED = 2;
        int cameras = 0;
    public:
        int DFS(TreeNode* root)
        {
            if(root == nullptr) return COVERED;

            int left = DFS(root->left);
            int right = DFS(root->right);

            if(left == 0 || right == 0) {
                cameras++;
                return HAS_CAMERA;
            }
            if(left == 1 || right == 1) {
                return COVERED;
            }
            return NOT_COVERED;
        }

        int minCameraCover(TreeNode* root) 
        {
            if(DFS(root) == NOT_COVERED) cameras++;
            return cameras;
        }
};

int main()
{
    return 0;
}