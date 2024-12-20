#include<iostream>
using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// By using BFS
class Solution 
{
    public:
        TreeNode* reverseOddLevels(TreeNode* root) 
        {
            if (root == NULL) return 0;
    
            struct TreeNode* queue[16500]; 
            int front = 0, rear = 0;
            queue[rear++] = root;
            int level = 1;

            while (front < rear)
            {
                int tmp = rear - front;
                for (int i = 0; i < tmp; i++)
                {
                    struct TreeNode* tmp_node = queue[front++];
                
                    if (tmp_node->left != NULL){
                        queue[rear++] = tmp_node->left;
                    }
                    if (tmp_node->right != NULL){
                        queue[rear++] = tmp_node->right;
                    }
                }
                if(level % 2 == 1) {
                    int left = front,right = rear-1;
                    while(left < right) 
                    {
                        int temp = queue[left]->val;
                        queue[left]->val = queue[right]->val;
                        queue[right]->val = temp;

                        left++;
                        right--;
                    }
                }
                level++;
            } 
            return root;     
        }
};

// By using DFS
class Solution 
{
    public:
        TreeNode* reverseOddLevels(TreeNode* root) {
            traverseDFS(root->left, root->right, 0);
            return root;
        }

    private:
        void traverseDFS(TreeNode* leftChild, TreeNode* rightChild, int level) {
            if (leftChild == nullptr || rightChild == nullptr) {
                return;
            }
            // If the current level is odd, swap the values of the children.
            if (level % 2 == 0) {
                int temp = leftChild->val;
                leftChild->val = rightChild->val;
                rightChild->val = temp;
            }

            traverseDFS(leftChild->left, rightChild->right, level + 1);
            traverseDFS(leftChild->right, rightChild->left, level + 1);
    }
};

int main()
{


    return 0;
}