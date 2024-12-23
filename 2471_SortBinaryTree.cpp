#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int minSwaps(vector<int> arr)
        {
            int swaps = 0;
            vector<vector<int>> mat;
            
            for(int i = 0; i < arr.size(); i++) {
                mat.push_back({arr[i],i});
            }
            sort(mat.begin(),mat.end());    

            for(int i = 0; i < arr.size(); i++) 
            {
                int index = mat[i][1];

                while(i != index)     
                {
                    swaps++;
                    swap(mat[i],mat[index]);
                    index = mat[i][1];
                }
            }
            return swaps;
        }

        int minimumOperations(TreeNode* root) 
        {
            if(root == NULL) return 0;

            struct TreeNode* queue[10000001];
            vector<int>level_arr;

            int front = 0,rear = 0;
            int operations = 0;

            queue[rear++] = root;

            // BFS to travel the tree
            while(front < rear) 
            {
                level_arr.clear();
                int tmp = rear - front;
                for(int i = 0; i < tmp; i++)
                {
                    struct TreeNode* tmp_node = queue[front++];
                    level_arr.push_back(tmp_node->val);

                    if(tmp_node->left != NULL) {
                        queue[rear++] = tmp_node->left;
                    }
                    if(tmp_node->right != NULL) {
                        queue[rear++] = tmp_node->right;
                    }
                }
                operations += minSwaps(level_arr);
            }

            return operations;
        }
};

int main()
{


    return 0;
}