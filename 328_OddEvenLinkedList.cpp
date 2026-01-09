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
        ListNode* oddEvenList(ListNode* head) 
        {
            if(head == nullptr || head->next == nullptr) return head;

            ListNode *_prev = head;
            ListNode *_curr = head->next;
            ListNode *_link = _curr;

            while(_curr && _curr->next) 
            {
                _prev->next = _curr->next;
                _prev = _prev->next;

                _curr->next = _prev->next;
                _curr = _curr->next;
            }
            _prev->next = _link;
            return head;
        }
};

int main()
{

    return 0;
}