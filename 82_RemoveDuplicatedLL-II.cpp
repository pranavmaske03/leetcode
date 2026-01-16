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
            ListNode dummy(0);
            dummy.next = head;

            ListNode *prev = &dummy;
            ListNode *curr = head;

            while(curr) 
            {
                ListNode *next_node = curr->next;
                while(next_node && curr->val == next_node->val) {
                    next_node = next_node->next;
                }

                if(curr->next != next_node) {
                    prev->next = next_node;
                } else {
                    prev = curr;
                }
                curr = next_node;
            }
            return dummy.next;
        }
};

int main()
{
    return 0;
}