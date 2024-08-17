#include"LinkedList.h"
#include<stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge(struct ListNode* list1, struct ListNode* list2) {
    
    //base case - if list is empty
    if (list1 == NULL) {
        return list2;
    } 
    
    //base case - if list is empty
    if (list2 == NULL) {
        return list1;
    }

    //check values
    if (list1->val < list2->val) {
        list1->next = merge(list1->next, list2);
        return list1;
    } else {
        list2->next = merge(list1, list2->next);
        return list2;
    }
}

struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head, *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev) {
    prev->next = NULL;
    }

    return slow;
}

struct ListNode* sortList(struct ListNode* head){
    
    //null checks and one element list check
    if (head == NULL || head->next == NULL) {
        return head;
    }

    //find middle of current list
    struct ListNode* middle = findMiddle(head);
    
    //recursive calls to continue to split the lists
    struct ListNode* right = sortList(middle); //middle acts as head of right list
    struct ListNode* left = sortList(head);

    //return merged list
    return merge(left, right);
}

int main()
{
    struct Node* first = NULL;
    struct Node* ret = NULL;

    InsertLastSLL(&first,7);
    InsertLastSLL(&first,6);
    InsertLastSLL(&first,5);
    InsertLastSLL(&first,4);
    InsertLastSLL(&first,8);
    InsertLastSLL(&first,3);
    InsertLastSLL(&first,2);
    InsertLastSLL(&first,1);
    printf("LinkedList before sorting \n");
    DisplaySLL(first);
    printf("LinkedList after sorting\n");
    ret = sortList(first);
    DisplaySLL(ret);

    return 0;
}