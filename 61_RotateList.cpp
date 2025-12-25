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
        ListNode* rotateRight(ListNode* head, int k) 
        {
            if(head == nullptr || head->next == nullptr) return head;

            ListNode *_first = head, *_last = head;
            int count = 1;

            while(_last->next) {
                ++count;
                _last = _last->next;
            }
            k %= count;
            for(int i = 1; i < count - k; i++) {
                _first = _first->next;
            }
            _last->next = head;
            ListNode *tmp = _first->next;
            _first->next = nullptr;
            return tmp;
        }
};

int main()
{

    return 0;
}