#include<iostream>
#include<vector>
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
        ListNode* reverseLL(ListNode* head)
        {
            ListNode* prev = nullptr;
            ListNode* curr = head;

            while(curr != nullptr)
            {
                ListNode *tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            return prev;
        }

        bool isPalindrome(ListNode* head) 
        {
            ListNode* _slow = head,* _fast = head;

            while(_fast->next && _fast->next->next) {
                _slow = _slow->next;
                _fast = _fast->next->next;
            }

            ListNode* _newHead = reverseLL(_slow->next);
            _slow->next = nullptr;
            while(head && _newHead) {
                if(head->val != _newHead->val) return false;
                head = head->next;
                _newHead = _newHead->next;
            }
            return true;
        }

        // 2nd Approach
        bool isPalindrome1(ListNode* head) 
        {
            vector<int> nodeValues;
            ListNode *tmp = head;

            while(tmp != nullptr) {
                nodeValues.push_back(tmp->val);
                tmp = tmp->next;
            }

            int n = nodeValues.size();
            for(int i = 0; i < n; i++) 
            {
                if(nodeValues[i] != nodeValues[n - i - 1]) {
                    return false;
                }
            }
            return true;
        }
};

int main()
{

    return 0;
}