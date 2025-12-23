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
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            if(head == NULL || head->next == NULL) return NULL;

            int total_nodes = 0;
            ListNode *_curr = head;
            ListNode *_prev = head;

            while(_curr != nullptr) {
                if(total_nodes > n) _prev = _prev->next;
                total_nodes++;
                _curr = _curr->next;
            }
            if(total_nodes == n) return _prev->next;
            else _prev->next = _prev->next->next;

            return head;
        }
};

int main()
{

    return 0;
}