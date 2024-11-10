#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void Insert(struct ListNode **Head,int iNo)
{
    struct ListNode* temp = *Head;
    struct ListNode* newn = NULL;

    newn = (struct ListNode*)malloc(sizeof(struct ListNode));
    newn->val = iNo;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Display(struct ListNode *head)
{
    while(head != NULL)
    {
        printf("%d\t",head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode *head = NULL;
    struct ListNode *temp = NULL;

    if(list1 == NULL)
    {
        return list2;
    }
    if(list2 == NULL)
    {
        return list1;
    }

    if(list1->val < list2->val)
    {
        head = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        list2 = list2->next;
    }

    temp = head;
    while((list1 != NULL) && (list2 != NULL))
    {
        if(list1->val < list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else 
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    while(list1 != NULL)
    {
        temp->next = list1;
        list1 = list1->next;
    }
    while(list2 != NULL)
    {
        temp->next = list2;
        list2 = list2->next;
    }

    return head;
}

struct ListNode* mergeTwoLists1(struct ListNode* l1, struct ListNode* l2) 
{
    if(l1 == NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }

    if(l1->val <= l2->val) 
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
     else 
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}


int main()
{
    struct ListNode* first1 = NULL;
    struct ListNode* first2 = NULL;
    struct ListNode *ret = NULL;

    Insert(&first1,2);
    Insert(&first1,2);
    Insert(&first1,4);
    Display(first1);
    Insert(&first2,1);
    Insert(&first2,3);
    Insert(&first2,4);
    Display(first2);

    ret = mergeTwoLists(first1,first2);
    Display(ret);

    return 0;
}