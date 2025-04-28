#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
    public:
        bool hasCycle(ListNode *head) 
        {
            ListNode *_slow = head, *_fast = head;

            while(_slow != NULL) { 
                if(_fast == NULL || _fast->next == NULL) return false;

                _slow = _slow->next;
                _fast = _fast->next->next;

                if(_slow == _fast) return true;
            }
            return false;
        }
};

int main()
{

    return 0;
}