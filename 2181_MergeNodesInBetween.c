#include"LinkedList.h"

struct Node* mergeNodes(struct Node* head) 
{
    if(!head) return NULL;
    
    struct Node *tmp_node = head;
    struct Node *h1 = head;
    head = head->next;
    int sum = 0;

    while(head != NULL)
    {
        if(head->data != 0)
        {
            sum = sum + head->data;
        }
        else
        {
            tmp_node->data = sum;
            tmp_node->next = head->next;
            tmp_node = tmp_node->next;
            sum = 0;
        }
        head = head->next;
    }
    return h1;
}

int main()
{
    struct Node* first = NULL;
    struct Node* ret = NULL;

    InsertFirstSLL(&first,0);
    InsertFirstSLL(&first,2);
    InsertFirstSLL(&first,5);
    InsertFirstSLL(&first,4);
    InsertFirstSLL(&first,0);
    InsertFirstSLL(&first,1);
    InsertFirstSLL(&first,3);
    InsertFirstSLL(&first,0);
    DisplaySLL(first);
    
    ret = mergeNodes(first);
    DisplaySLL(ret);

    return 0;
}