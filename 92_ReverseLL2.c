#include"LinkedList.h"

struct Node* reverseBetween(struct Node* head, int left, int right) 
{
    if(head == NULL || head->next == NULL) return head;
    if(left == right) return head;

    struct Node *tmp_node = head,*temp = NULL;
    struct Node *first = head,*last = head,*t = NULL;
    int count = 0;
    while(last != NULL)
    {   
        count++;
        if(count < left) t = last;
        if(count == left) 
        {
            first = last;
            temp = last;
        }
        if(count > left)
        {   
            tmp_node = last;
            last = last->next;
            tmp_node->next = first;
            first = tmp_node;
        }
        else
        {
            last = last->next;
        }
        if(count == right) 
        {
            if(left == 1)
            {
                temp->next = last;
                return first;
            }
            else
            {
                temp->next = last;
                t->next = first;
            }
            break;
        }
    }
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
   // InsertLastSLL(&first,6);
    //InsertLastSLL(&first,7);
    //InsertLastSLL(&first,8);
    DisplaySLL(first);

    printf("Reversed Linked List is : \n");
    ret = reverseBetween(first,3,4);
    DisplaySLL(ret);

    return 0;
}