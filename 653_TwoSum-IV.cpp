#include<iostream>
#include<unordered_set>
using namespace std;

class Solution 
{
        unordered_set<int> st;
    public:
        bool findTarget(TreeNode* root, int k) 
        {   
            // Using BFS traversal
            // if (!root) return false;
            // queue<TreeNode*> q;
            // q.push(root);

            // while (!q.empty()) 
            // {
            //     TreeNode* tmp = q.front();
            //     q.pop();

            //     if(st.count(k - tmp->val)) {
            //         return true;
            //     }
            //     st.insert(tmp->val);

            //     if (tmp->left) q.push(tmp->left);
            //     if (tmp->right) q.push(tmp->right);
            // }
            // return false;


            // Using DFS Traversal
            if(!root) return false;

            if(st.count(k - root->val)) {
                return true;
            }
            st.insert(root->val);
            return findTarget(root->left,k) || findTarget(root->right,k);
        }
};


int main()
{

    return 0;
}