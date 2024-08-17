#include<stdio.h>

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode *tmp = NULL;
    int c = 1;

    while(headA != NULL)
    {
        tmp = headB;
        while(tmp != NULL)
        {
            if(tmp == headA)
            {
                c = -1;
                break;
            }
            tmp = tmp->next;
        }
        if(c == -1) break;
        headA = headA->next;
    }
    return headA;
}

int main()
{


    return 0;
}