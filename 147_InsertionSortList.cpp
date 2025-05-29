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
        ListNode* insertionSortList(ListNode* head) 
        {
            if (!head || !head->next) return head;

            ListNode* dummy = new ListNode();
            dummy->next = head;

            ListNode *curr = head->next;
            ListNode *prev = head;

            while(curr != nullptr) 
            {
                ListNode *next = curr->next;
                if (curr->val >= prev->val) {              
                    prev = curr;
                    curr = next;
                } else if(dummy->next->val > curr->val) {
                    prev->next = curr->next;
                    curr->next = dummy->next;
                    dummy->next = curr;
                } else {
                    ListNode *tmp = dummy->next;
                    while(tmp->next && tmp->next->val < curr->val) {
                        tmp = tmp->next;
                    }
                    prev->next = curr->next;
                    curr->next = tmp->next;
                    tmp->next = curr;
                }
                curr = next;
            }
            return dummy->next;
        }
};

int main()
{

    return 0;
}