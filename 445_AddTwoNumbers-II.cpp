#include<iostream>
#include<stack>
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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            if(!l1) return l2;
            if(!l2) return l1;

            stack<int> st1;
            stack<int> st2;
            int carry = 0;

            ListNode dummy(0);
            ListNode *curr = &dummy;
            ListNode *tmp = l1;
            while(l1) {
                st1.push(l1->val);
                l1 = l1->next;
            }
            tmp = l2;
            while(l2) {
                st2.push(l2->val);
                l2 = l2->next;
            }

            while((!st1.empty()) || (!st2.empty()) || carry) 
            {
                int sum = carry;
                if(!st1.empty()) {
                    sum += st1.top();
                    st1.pop();
                }
                if(!st2.empty()) {
                    sum += st2.top();
                    st2.pop();
                }

                carry = sum/10;
                ListNode *newn = new ListNode(sum%10);

                newn->next = curr->next;
                curr->next = newn;
            }
            return dummy.next;
        }
};

int main()
{
    return 0;
}