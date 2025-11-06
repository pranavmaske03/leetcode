#include<iostream>
#include<vector>
#include<bitset>
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
        ListNode* modifiedList(vector<int>& nums, ListNode* head) 
        {
            bitset<1000001> map;
            for (int num : nums) map[num] = 1;

            ListNode* demo = new ListNode();
            ListNode* tmp = demo;

            while (head != NULL)
            {
                if (!map[head->val]) {
                    tmp->next = head;
                    tmp = head;
                }
                head = head->next;
            }
            tmp->next = NULL;
            return demo->next;
        }
};

int main()
{

    return 0;
}