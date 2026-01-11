#include<iostream>
#include<queue>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution 
{
    public:
        Node* connect(Node* root) 
        {
            if(!root) return nullptr;

            queue<Node*> queue;
            Node *prev = nullptr;
            Node *curr = nullptr;

            queue.push(root);

            while(!queue.empty())
            {
                int levelSize = queue.size();

                for(int i = 0; i < levelSize; i++) {
                    curr = queue.front();
                    queue.pop();

                    if(i > 0) prev->next = curr;
                    if(curr->left) queue.push(curr->left);
                    if(curr->right) queue.push(curr->right);
                    prev = curr;
                }
                curr->next = nullptr;
            }
            return root;
        }
};
int main()
{

    return 0;
}