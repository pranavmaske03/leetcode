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
        ListNode* deleteDuplicates(ListNode* head) 
        {
            if(head == NULL || head->next == NULL) return head;

            ListNode* _prev = head;
            ListNode* _curr = head->next;

            while(_curr)
            {
                if(_prev->val != _curr->val) {
                    _prev->next = _curr;
                    _prev = _curr;
                }
                _curr = _curr->next;
            }
            _prev->next = NULL;
            return head;
        }
};

int main()
{
    return 0;
}