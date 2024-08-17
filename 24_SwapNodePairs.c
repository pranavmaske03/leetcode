#include"LinkedList.h"

struct Node* swapPairs(struct Node* head) 
{
    struct Node* dummy = malloc(sizeof(struct Node));
    dummy->next = head->next;
    struct Node *curr = head,*temp = head->next,*prev = head,*tempX = NULL;
    int k = 1;

    while(curr && curr->next)
    {
        tempX = temp->next;
        temp->next = curr;
        curr->next = tempX;
        if(k == 2)
        {
            prev->next = temp;
            prev = curr;
            k = 1;
        }
        k++;
        DisplaySLL(dummy->next);
        if(curr->next == NULL) break;
        curr = curr->next;
        temp = curr->next;
    }

    return dummy->next;
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

    ret = swapPairs(first);
   // DisplaySLL(ret);

    return 0;
}