#include"LinkedList.h"

void deleteNode(struct Node* node) 
{
    struct Node *tmp = node->next;
    while(tmp != NULL)    
    {
        node->data = tmp->data;
        tmp = tmp->next;
        if(tmp != NULL) node = node->next;
    }
    node->next = NULL;
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
    InsertLastSLL(&first,8);
    DisplaySLL(first);

    ret =  first->next->next->next;
    deleteNode(ret);
    DisplaySLL(first);

    return 0;
}