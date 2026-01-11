#include"LinkedList.h"

struct Node* middleNode(struct Node* head) 
{
    if(head == NULL || head->next == NULL) return NULL;
    struct Node *_slow = head;
    struct Node *_fast = head->next->next;
    struct Node *tmp = NULL;

    while(_fast && _fast->next) 
    {
        _fast = _fast->next->next;
        _slow = _slow->next;
    }
    tmp = _slow->next;
    _slow->next = _slow->next->next;
    free(tmp);
    return head;
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

    ret = middleNode(first);
    DisplaySLL(ret);

    return 0;
}