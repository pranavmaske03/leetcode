#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution 
{
    public:
        vector<int> largestValues(TreeNode* root) 
        {
            // result array to return max values at each level
            vector<int>result;

            // queue to travel tree using BST algoritham
            struct TreeNode *queue[1000001]; 
            struct TreeNode *tmp_node = NULL;  

            // rear and front pointer to points end and starting of the queue
            int rear = 0,front = 0; 
            int tmp = 0,max = 0;

            // root is not null insert it to the queue
            if(root != NULL) queue[rear++] = root;

            // BST traversal
            while(front < rear) 
            {
                // to get the count of element at corresponding level
                tmp = rear - front;
                max = INT32_MIN;

                for(int i = 1; i <= tmp; i++) 
                {
                    // get the queue element one by one
                    tmp_node = queue[front++];
                    
                    // check max with the current node
                    max = max < tmp_node->val ? tmp_node->val : max; 

                    // insert the nodes in queue
                    if(tmp_node->left) {
                        queue[rear++] = tmp_node->left;
                    }
                    if(tmp_node->right) {
                        queue[rear++] = tmp_node->right;                   
                    }
                }
                result.push_back(max);
            }
            return result;       
        }
};

int main()
{

    return 0;
}