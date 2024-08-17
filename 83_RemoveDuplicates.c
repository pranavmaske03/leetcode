#include<stdio.h>

struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode* temp = head;
    struct ListNode* tempX = NULL;
    
    if(head == NULL || head->next == NULL){
        return head;
    }

    while(temp->next != NULL)
    {      
        tempX = temp->next;
        if(temp->val == tempX->val)
        {
            temp->next = tempX->next;
            free(tempX);
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{


    return 0;
}