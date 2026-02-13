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
    //  Solution using recursive DFS
        int i = 0;
        TreeNode* recoverFromPreorder(string& s, int depth = 0) 
        {
            if(i >= s.length()) return nullptr;

            int curr_depth = 0;
            while(i < s.length() && s[i] == '-') curr_depth++, i++;


            // If depth does not match expected depth,
            // this node does not belong to this subtree
            if(curr_depth < depth) {
                i -= curr_depth;    // backtrack index
                return nullptr;
            }

            int val = 0;
            while(i < s.length() && isdigit(s[i])) {
                val = (val * 10) + (s[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);

            node->left = recoverFromPreorder(s, depth + 1);
            node->right = recoverFromPreorder(s, depth + 1);

            return node;
        }

        
    // Iterative approach using vector as a stack
    TreeNode* recoverFromPreorder(string S) {
        vector<TreeNode*> stack;
        int n = S.length();

        for (int i = 0, level, val; i < n;) {
            for (level = 0; i < n && S[i] == '-'; i++)
                level++;
            for (val = 0; i < n && S[i] != '-'; i++)
                val = val * 10 + S[i] - '0';

            while (stack.size() > level) {
                stack.pop_back();
            }
            TreeNode* node = new TreeNode(val);

            if (!stack.empty()) {
                if (!stack.back()->left)
                    stack.back()->left = node;
                else
                    stack.back()->right = node;
            }
            stack.push_back(node);
        }
        return stack[0];
    }
};
 
int main()
{
    return 0;
}