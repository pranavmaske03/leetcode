#include"LinkedList.h"

void reorderList(struct Node* head) 
{
    if(head == NULL || head->next == NULL || head->next->next == NULL) return;
    
    struct Node *last = head;
    while(last->next->next != NULL)
    {
        last = last->next;
    }

    last->next->next = head->next;
    head->next = last->next;
    last->next = NULL;
    reorderList(head->next->next);
} 

int main()
{
    struct Node* first = NULL;

    InsertLastSLL(&first,1);
    InsertLastSLL(&first,2);
    InsertLastSLL(&first,3);
    InsertLastSLL(&first,4);
    InsertLastSLL(&first,5);            
    InsertLastSLL(&first,6);
    InsertLastSLL(&first,7);
    InsertLastSLL(&first,8);
    //InsertLastSLL(&first,2);
    DisplaySLL(first);
    reorderList(first);
    DisplaySLL(first);

    return 0;
}


/*
// reverse linked list
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) { 
        return head;
    }
    
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = NULL;
    
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    return prev;
}

void reorderList(struct ListNode* head) {
    struct ListNode* newHead = NULL; // 
    struct ListNode* newNode = NULL; // 
    struct ListNode* node = head;
    
    if(head == NULL || head->next == NULL) { // 
        return;
    }
    
    // find the middle nodes
    struct ListNode* slow = head;
    struct ListNode* fast = head->next->next;
    while(fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast != NULL) 
    { 
        slow = slow->next; 
    }
    
    newHead = slow->next; 
    slow->next = NULL;
    
    reverse the 2nd linked list
    newHead = reverseList(newHead);
    
    merge 2 linked list together
    newNode = newHead;
    node = head;
    int index = 0;
    while(newNode != NULL && node != NULL) 
    {
        if((index % 2) == 0) 
        { 
            struct ListNode* next = node->next;
            node->next = newNode;
            node = next;
        }
        else 
        { 
            struct ListNode* next = newNode->next;
            newNode->next = node;
            newNode = next;
        }
        index++;
    }    
}
*/