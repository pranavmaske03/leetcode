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

// Using DFS - technnique
class Codec 
{
    public:
    // Encodes a tree to a single string.
    void preorder(TreeNode* root, string& s) {
        if (!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    // Decodes your encoded data to tree. 
    TreeNode* build(const string& s, int& i) {
        if(s[i] == '#') {
            i += 2;
            return nullptr;
        }

        int num = 0;
        while(s[i] != ',') {
            num = num * 10 + (s[i++] - '0');
        }
        i++;

        TreeNode* root = new TreeNode(num);
        root->left = build(s, i);
        root->right = build(s, i);
        return root;
    }
    TreeNode* deserialize(string s) {
        int i = 0;
        return build(s, i);
    }
};

// using BFS technique
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