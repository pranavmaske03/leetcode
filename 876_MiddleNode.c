#include"LinkedList.h"

struct Node* middleNode(struct Node* head) 
{
    int count = 0;
    struct Node *_fast = head;
    struct Node *_slow = head;

    while(_slow != NULL) 
    {
        if(_fast == NULL || _fast->next == NULL)
        {
            break;
        }
        _slow = _slow->next;
        _fast = _fast->next->next;
    }
    printf("%d\n",count);
    return _slow;
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