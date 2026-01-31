#include<iostream>
#include<queue>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
    public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#,";

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    // Decodes your encoded data to tree.
    TreeNode* DFS(stringstream& ss) {
        string token = "";
        getline(ss,token,',');
        if(token == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(token));
        root->left = DFS(ss);
        root->right = DFS(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream ss(data);
        return DFS(ss);
    }
};

class Codec 
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#"; // Return a simple marker for empty trees
        
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr == nullptr) {
                s += "#,";
            } else {
                s += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return nullptr; // Handle empty tree case

        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            // Handle Left Child
            if(!getline(s, str, ',')) break;
            if(str == "#") {
                curr->left = nullptr;
            } else {
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }

            // Handle Right Child
            if(!getline(s, str, ',')) break;
            if(str == "#") {
                curr->right = nullptr;
            } else {
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return root;
    }
};
int main()
{
    return 0;
}