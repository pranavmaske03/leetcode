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
        int gcd(int a, int b)
        {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        ListNode* insertGreatestCommonDivisors(ListNode* head) 
        {
            if(head == nullptr || head->next == nullptr) return head;

            ListNode *prev = head;
            ListNode *curr = head->next;

            while(curr)
            {
                int val = gcd(prev->val,curr->val);
                ListNode *node = new ListNode(val);

                node->next = prev->next;
                prev->next = node;

                prev = curr;
                curr = curr->next;
            }
            return head;
        }
};

int main()
{
    return 0;
}