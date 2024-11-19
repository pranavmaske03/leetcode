#include"LinkedList.h"
#include<stdlib.h>

struct Node* rotateRight(struct Node* head, int k) 
{
    if(head == NULL || head->next == NULL) return head;
    struct Node *first = head,*last = head;
    struct Node *ret = head;
    int count = 1,n = 0;

    while(last->next != NULL)
    {
        ++count;
        last = last->next;
    }
    n = k%count;
    printf("%d\t%d\n",count,n);
    for(int i = 1; i < count-n; i++)
    {
        first = first->next;
    }
    last->next = head;
    ret = first->next;
    first->next = NULL;
    return ret;
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
    //InsertLastSLL(&first,6);
    //InsertLastSLL(&first,7);
    //InsertLastSLL(&first,8);   
   
    DisplaySLL(first);

    printf("Reversed Linked List is : \n");
    ret = rotateRight(first,2);
    DisplaySLL(ret);

    return 0;
}