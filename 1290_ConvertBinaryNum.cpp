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
        int getDecimalValue(ListNode* head) 
        {
            ListNode* _tmp = head;
            int power = 0;
            int base = 2;
            int num = 0;

            while(_tmp) {
                power++;
                _tmp = _tmp->next;
            }

            _tmp = head;
            for(int i = 1; i <= power; i++)
            {
                num += pow(base,(power - i)) * _tmp->val;
                _tmp = _tmp->next;
            }
            return num;
        }
        
        // using bit manipulation technique
        int getDecimalValue(ListNode* head) 
        {
            int num = 0;

            while(head) {
                num = (num << 1) | head->val;
                head = head->next;
            }
            return num;
        }
};

int main()
{
    return 0;
}