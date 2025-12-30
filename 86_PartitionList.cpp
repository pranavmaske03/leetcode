#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
    public:
        ListNode* partition(ListNode* head, int x) 
        {
            ListNode _dummy;
            _dummy.next = head;
            ListNode* _prev = &_dummy;
            ListNode* _curr = &_dummy;

            while(_prev->next && _prev->next->val < x)  {
                _prev = _prev->next;
            }
            
            _curr = _prev;
            while(_curr->next)
            {
                if(_curr->next->val < x) {   
                    ListNode* _node = _curr->next;
                    _curr->next = _node->next;

                    _node->next = _prev->next;
                    _prev->next = _node;

                    _prev = _node;
                } else {
                    _curr = _curr->next;
                }
            }
            return _dummy.next;
        }

        // using two separate list
        ListNode* partition(ListNode* head, int x) 
        {
            ListNode _smalldummy,_greaterdummy;
            ListNode* _smaller = &_smalldummy;
            ListNode* _greater = &_greaterdummy;

            while(head)
            {
                if(head->val < x) {
                    _smaller->next = head;
                    _smaller = _smaller->next;
                } else {
                    _greater->next = head;
                    _greater = _greater->next;
                }
                head = head->next;
            }
            _greater->next = nullptr;
            _smaller->next = _greaterdummy.next;

            return _smalldummy.next;
        }
};

int main()
{

    return 0;
}