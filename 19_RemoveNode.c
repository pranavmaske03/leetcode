#include"LinkedList.h"

struct Node* removeNthFromEnd(struct Node* head, int n) 
{
    if(head == NULL || head->next == NULL) return head;
    struct Node *curr = head;
    struct Node *prev = head;
    int count = 0;

    while(curr != NULL)
    {
        if(count > n) prev = prev->next;
        count++;
        curr = curr->next;
    }
    printf("%d\n",prev->data);
    if(count == n) {
        return prev->next;
    }
    else{
        prev->next = prev->next->next;
        return head;
    }
}

int main()
{
    struct Node* first = NULL;
    struct Node* ret = NULL;

    InsertLastSLL(&first,1);
    InsertLastSLL(&first,2);
   // InsertLastSLL(&first,3);
  //  InsertLastSLL(&first,4);
   // InsertLastSLL(&first,5);
    //InsertLastSLL(&first,6);
   // InsertLastSLL(&first,7);
    //InsertLastSLL(&first,8);
    DisplaySLL(first);

    ret = removeNthFromEnd(first,2);
    DisplaySLL(ret);

    return 0;
}