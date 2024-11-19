#include"LinkedList.h"

struct Node* deleteDuplicates(struct Node* head)
{
        struct Node *dummy = malloc(sizeof(struct Node));
        dummy->next = head;
        dummy->data = 0;
        struct Node *prev = dummy , *curr = head;

        while(curr)
        {
            struct Node *next_node = curr->next;
            while(next_node && curr->data == next_node->data)
            {
                struct Node *temp = next_node->next;
                // delete next_node;
                next_node = temp;
            }

            if(curr->next != next_node)
            {
                prev->next = next_node;
                // delete curr;
            }
            else
            {
                prev = curr;

            }
            curr = next_node;
        }
        return dummy->next;
}
int main()
{
    struct Node* first = NULL;
    struct Node* ret = NULL;

    InsertLastSLL(&first,1);
    InsertLastSLL(&first,2);
    InsertLastSLL(&first,2);
    InsertLastSLL(&first,3);
    InsertLastSLL(&first,5);
    InsertLastSLL(&first,6);
    //1,2,3,3,4,4,5
    ret = deleteDuplicates(first);

    DisplaySLL(ret);
    return 0;
}