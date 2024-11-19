#include<stdio.h>
#include"LinkedList.h"

bool hasCycle(struct Node *head) 
{   
    if(head == NULL) return false;
    if(head->next == NULL) return false;

    int Arr[100];
    int i = 0,j = 0;
    bool flag = false;

    Arr[i++] = head->data;
    head = head->next;
    while(head != NULL)
    {
        for(j = 0; j < i; j++)
        {
            if(Arr[j] == head->data)
            {
                flag = true;
                break;
            }
        }
        if(flag == true) break;
        Arr[i++] = head->data;
        head = head->next;
    }
    return flag;
}

bool hasCycle1(struct ListNode *head) 
{
    if(head == NULL) return false;

    struct Node *_slow = head,*_fast = head;

    while(_slow != NULL) 
    {
        if(_fast == NULL || _fast->next == NULL)
        {
            return false;
        }
        _slow = _slow->next;
        _fast = _fast->next->next;

        if(_slow == _fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    struct Node *first = NULL;
    bool bRet = false;

    InsertFirstSLL(&first,55);
    InsertFirstSLL(&first,44);
    InsertFirstSLL(&first,33);
    InsertFirstSLL(&first,22);
    InsertFirstSLL(&first,11);
    //DisplaySLL(first);

    bRet = hasCycle(first);
    if(bRet == true)
    {
        printf("Cycle\n");
    }
    else
    {
        printf("NOT cycle\n");
    }

    return 0;
}