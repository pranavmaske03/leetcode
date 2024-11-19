#include"LinkedList.h"
#include<stdlib.h>

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

int main()
{
    struct Node* first = NULL;
    struct Node* ret = NULL;

    InsertLastSLL(&first,1);
    InsertLastSLL(&first,2);
    InsertLastSLL(&first,3);
    InsertLastSLL(&first,4);
    InsertLastSLL(&first,5);
    InsertLastSLL(&first,6);
    InsertLastSLL(&first,7);
    DisplaySLL(first);

    printf("Reversed Linked List is : \n");
    ret = reverseList(first);
    DisplaySLL(ret);

    return 0;
}