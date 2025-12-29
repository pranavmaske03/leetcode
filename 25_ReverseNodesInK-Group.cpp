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
        ListNode* reverseList(ListNode* _first, ListNode* _last)
        {
            ListNode* _prev = nullptr;
            ListNode* _curr = _first;
            ListNode* _next = nullptr;

            while(_prev != _last)
            {
                _next = _curr->next;
                _curr->next = _prev;
                _prev = _curr;
                _curr = _next;
            }
            return _last;
        }

        ListNode* reverseKGroup(ListNode* head, int k) 
        {
            if (k == 1 || !head) return head;

            ListNode* _first = nullptr;
            ListNode* _next = nullptr;
            ListNode _dummy;
            ListNode* _manage = &_dummy;
            int count = 0;

            while(head)
            {
                if(count == 0) _first = head;
                _next = head->next;
                ++count;
                if(count == k) {
                    _manage->next = reverseList(_first,head);
                    _manage = _first;
                    count = 0;
                }
                head = _next;
            }
            if(count != 0) {
                _manage->next = _first;
            }
            return _dummy.next;
        }
};

int main()
{

    return 0;
}