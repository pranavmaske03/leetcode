#include<iostream>
#include<vector>
#include<pair>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;y
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int row, int col, vector<pair<int,pair<int,int>>>& nodes) {
        if(root == nullptr) return;
        nodes.emplace_back(col, make_pair(row, root->val));
        dfs(root->left, row + 1, col - 1, nodes);
        dfs(root->right, row + 1, col + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int,pair<int,int>>> nodes;
        dfs(root, 0, 0, nodes);
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> res;
        int prevCol = INT_MIN;

        for (const auto &node : nodes) {
            int col = node.first;
            int row = node.second.first;
            int val = node.second.second;

            if(col != prevCol) {
                res.push_back({});
                prevCol = col;
            }
            res.back().push_back(val);
        }
        return res;
    }
};

int main()
{
    return 0;
}