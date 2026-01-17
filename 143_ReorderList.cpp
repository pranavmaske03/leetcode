#include<iostream>
using namespace std;

class Solution 
{
    public:
        ListNode* reverse(ListNode* head)
        {
            ListNode *prev = nullptr;
            ListNode *curr = head;

            while(curr) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            return prev;
        }

        void reorderList(ListNode* head) 
        {
            if(!head || !head->next) return;

            ListNode *slow = head;
            ListNode *fast = head;

            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode *second = slow->next;
            slow->next = nullptr;

            second = reverse(second);
            ListNode *first = head;

            while(second) {
                ListNode *tmp1 = first->next;
                ListNode *tmp2 = second->next;

                first->next = second;
                second->next = tmp1;

                first = tmp1;
                second = tmp2;
            }
        }
};

int main()
{
    return 0;
}