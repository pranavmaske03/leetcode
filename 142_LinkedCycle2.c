#include"LinkedList.h"

struct Node *detectCycle(struct Node *head)
{
    if(head == NULL || head->next == NULL) return NULL;
    struct Node *_slow = head,*_fast = head;
    bool flag = false;

    while(_slow != NULL) 
    {
        if(_fast == NULL || _fast->next == NULL)
        {
            return NULL;
        }
        _slow = _slow->next;
        _fast = _fast->next->next;

        if(_slow == _fast)
        {
            flag = true;
            break;
        }
    }
    _slow = head;
    if(flag){
        while(_slow != _fast) {
            _slow = _slow->next;
            _fast = _fast->next;
        }
        return _slow;
    }   
    return NULL;
}


int main()
{


    return 0;
}