#include"LinkedList.h"
#include<stdlib.h>

struct Node* deleteDuplicates(struct Node* head,int val)
{
    if(head == NULL) return head;

    struct Node *tmp_node = NULL,*temp = NULL;
    tmp_node = malloc(sizeof(struct Node));

    tmp_node->data = -1;
    tmp_node->next = head;
    head = tmp_node;
    while(head->next != NULL)
    {
        if(head->next->data == val)
        {
            temp = head->next;
            head->next = head->next->next;
            free(temp);
        }
        else
        {
            head = head->next;
        }
    }
    return tmp_node->next;
}

int main()
{
    struct Node* first = NULL;
    struct Node* ret = NULL;

    InsertLastSLL(&first,7);
    InsertLastSLL(&first,7);
    InsertLastSLL(&first,7);
    InsertLastSLL(&first,7);
    InsertLastSLL(&first,7);
    InsertLastSLL(&first,7);
    InsertLastSLL(&first,7);
    // 1,2,6,3,4,5,6]
    ret = deleteDuplicates(first,7);

    DisplaySLL(ret);

    return 0;
}