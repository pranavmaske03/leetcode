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
        ListNode* mergeNodes(ListNode* head) 
        {
            ListNode* _prev = head;
            ListNode* _curr = head->next;
            int sum = 0;

            while (_curr) 
            {
                if (_curr->val != 0) 
                {
                    sum += _curr->val;
                } 
                else 
                {
                    _prev->val = sum;             
                    _prev->next = _curr->next;   
                    _prev = _prev->next;          
                    sum = 0;
                }
                _curr = _curr->next;             
            }
            return head;
        }
};

int main()
{
    return 0;
}