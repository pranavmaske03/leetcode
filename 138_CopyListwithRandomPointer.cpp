#include<iostream>
#include<unordered_map>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution 
{
    public:
        Node* copyRandomList(Node* head) 
        {
            unordered_map<Node*,Node*> mp;
            mp[nullptr] = nullptr;

            Node* _dummy = new Node(0);
            Node* _curr = head;
            Node* _tmp = _dummy;

            while(_curr) 
            {
                _tmp->next = new Node(_curr->val);
                mp[_curr] = _tmp->next;

                _curr = _curr->next;
                _tmp = _tmp->next;
            }

            _curr = head;
            _tmp = _dummy->next;

            while(_curr)
            {
                _tmp->random = mp[_curr->random];
                _curr = _curr->next;
                _tmp = _tmp->next;
            }

            return _dummy->next;
        }
};

int main()
{

    return 0;
}