#include"LinkedList.h"
#include<stdlib.h>

bool pallindrome(struct Node* head) 
{
    if(head == NULL && head->next == NULL) return head;

    struct Node* arr[100];
    int index = 0,i = 0; 
    bool flag = true;

    while(head != NULL)   
    {
        arr[index++] = head;
        head = head->next;
    }
    while(i < index-1)
    {
        if(arr[i++]->data != arr[--index]->data) 
        {
            flag = false;
            break;
        }
    }
    return flag;
}

/*
    solution without array 

struct Node* reverseList(struct Node* head) 
{
    if(head == NULL || head->next == NULL) return head;

    struct Node *tmp_node = NULL;
    struct Node *first = head,*last = head->next;

    first->next = NULL;
    while(last != NULL)
    {
        tmp_node = last;
        last = last->next;
        tmp_node->next = first;
        first = tmp_node;
    }
    return tmp_node;
}

bool isPalindrome(struct Node* head) 
{
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* tmp_node = NULL;
    bool flag = true;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    tmp_node = reverseList(slow->next);
    slow->next = NULL;
    while(head != NULL && tmp_node != NULL)
    {
        if(head->data != tmp_node->data)
        {
            flag = false;
            break;
        }
        head = head->next;
        tmp_node = tmp_node->next;
    }
    return flag;
}

*/

int main()
{
    struct Node* first = NULL;
    bool bret = false;

    InsertLastSLL(&first,1);
    InsertLastSLL(&first,2);
    InsertLastSLL(&first,3);
    InsertLastSLL(&first,4);
    InsertLastSLL(&first,3);
    InsertLastSLL(&first,2);
    InsertLastSLL(&first,1);
    DisplaySLL(first);

    bret = pallindrome(first);
    if(bret == true)
    {
        printf("LL is pallindrome\n");
    }
    else
    {
        printf("LL is NOT pallindrome\n");
    }

    return 0;
}