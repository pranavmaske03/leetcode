#include<iostream>
#include<stack>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution 
{
    public:
        Node* flatten(Node* head) 
        {
            if(!head) return nullptr;
            stack<Node*> st;
            Node *_curr = head;
            
            while(_curr != nullptr)
            {
                if(_curr->child) {
                    if(_curr->next) st.push(_curr->next);

                    _curr->next = _curr->child;
                    _curr->next->prev = _curr;
                    _curr->child = nullptr;
                }

                if(( !_curr->next ) && ( !st.empty() )) {
                    Node* _top = st.top();
                    st.pop();

                    _curr->next = _top;
                    _top->prev = _curr;
                }
                _curr = _curr->next;
            }
            return head;
        }
};

int main()
{
    return 0;
}