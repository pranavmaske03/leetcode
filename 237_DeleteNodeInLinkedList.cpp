#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
    public:
        void deleteNode(ListNode* node) 
        {
            ListNode *deleteNode = node->next;
            node->val = deleteNode->val;
            node->next = deleteNode->next;
            delete deleteNode;
        }
};

int main()
{
    return 0;
}