#include<iostream>
using namespace std; 

class Solution 
{
    public:
        ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
        {
            ListNode* before = list1;

            for(int i = 0;i<a-1;i++) {
                before = before->next;
            }

            ListNode* after = before->next;
            for(int i = 0;i<=b-a;i++) {
                after = after->next;
            }

            ListNode* tail2 = list2;
            while(tail2->next!=NULL) {
                tail2 = tail2->next;
            } 

            before->next = list2;
            tail2->next = after;

            return list1; 
        }
};

int main()
{
    return 0;
}