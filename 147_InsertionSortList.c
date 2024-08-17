#include<stdio.h>
#include"LinkedList.h"

struct Node* insertionSortList(struct Node* head) 
{
    struct Node* arr[5000];
    int k = 0,j = 0,i = 0,key = 0;
    struct Node *temp = head, *tempX = NULL;

    while(temp != NULL)
    {
        arr[k++] = temp;
        temp = temp->next;
    }
    temp = head;
    i = 1;
    while(temp != NULL && i < k)
    {
        key = arr[i]->data;
        j = i - 1;
        while(j >= 0 && arr[j]->data > key)
        {
            arr[j + 1]->data = arr[j]->data;
            j--;
        }
        arr[j + 1]->data = key;
        temp = temp->next;
        i++;
    }
    return head;
}

struct ListNode* insertionSortList(struct ListNode* head) 
{
    if (!head || !head->next) {
        return head;
    }

    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* prev = head;
    struct ListNode* cur = head->next;

    while (cur) {
        // already in-order
        if (prev->val <= cur->val) {
            prev = cur;
            cur = cur->next;
        } else {
            struct ListNode* temp = dummy;
            
            while(cur->val > temp->next->val) 
                temp = temp->next;

            // find the stop
            prev->next = cur->next;
            cur->next = temp->next;
            temp->next = cur;

            cur = prev->next;
        }
    }
    return dummy->next;
}

int main()
{
    struct Node* first = NULL;

    InsertLastSLL(&first,4);
    InsertLastSLL(&first,2);
    InsertLastSLL(&first,1);
    InsertLastSLL(&first,3);
    InsertLastSLL(&first,8);
    InsertLastSLL(&first,5);
    InsertLastSLL(&first,9);
    InsertLastSLL(&first,7);
    InsertLastSLL(&first,2);

    DisplaySLL(first);
    struct Node *ret = insertionSortList(first);
    DisplaySLL(ret);

    return 0;
}