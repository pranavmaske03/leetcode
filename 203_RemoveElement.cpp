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
        // with recursion
        ListNode* removeElements(ListNode* head, int val) 
        {
            if(head == nullptr) return nullptr;
            head->next = removeElements(head->next,val);

            if(head->val == val) {
                return head->next;
            } else {
                return head;
            }
        }
        // without recursion
        ListNode* removeElements(ListNode* head, int val) 
        {
            ListNode *_dummy = new ListNode();
            _dummy->next = head;

            ListNode *_curr = head;
            ListNode *_prev = _dummy;

            while(_curr) 
            {
                if(_curr->val == val) {
                    _prev->next = _curr->next;
                } else {
                    _prev = _curr;
                }
                _curr = _curr->next;
            }
            return _dummy->next;
        }
};

int main()
{

    return 0;
}