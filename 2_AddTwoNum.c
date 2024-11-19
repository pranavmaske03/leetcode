#include<stdio.h>
#include"LinkedList.h"

struct Node* addTwoNum(struct Node *l1,struct Node *l2)
{
    if(l1 == NULL || l2 == NULL) return NULL;
    struct Node *ret = l1;
    struct Node *tmp_node = l2,*last = NULL;
    int carry = 0;

    while(l1 != NULL && l2 != NULL)
    { 
        l1->data = l1->data + l2->data;
        if(carry > 0)
        {
            l1->data = l1->data + carry;
            carry = 0;
        }
        if(l1->data > 9)
        {
            l1->data = l1->data - 10;
            carry = 1;
        }
        last = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != NULL)
    {
        if(carry > 0)
        {
            l1->data = l1->data + carry;
            if(l1->data > 9)
            {
                l1->data = l1->data - 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }
        else
        {
            break;
        }
        last = l1;
        l1 = l1->next;
    }
    while(l2 != NULL)
    {
        if(carry > 0)
        {
            last->next = l2;
            l2->data = l2->data + carry;
            if(l2->data > 9)
            {
                l2->data = l2->data - 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }
        else
        {
            last->next = l2;
            break;
        }
        last = l2;
        l2 = l2->next;
    }
    if(carry > 0)
    {
        last->next = tmp_node;
        last = tmp_node;
        tmp_node = tmp_node->next;
        last->data = carry;
        last->next = NULL;
    }
    return ret;
}

struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode* temp = NULL, * ListNodelist = NULL, * t = NULL;
	int c = 1;
	bool carry = 0;
    
	while(1) 
    {
		
		int num = 0;
		if (l1 == NULL && l2 == NULL && !carry)break;
		
		if (l1 == NULL&&l2==NULL) {
			num = carry;
		}
		else if(l1 == NULL){
			num = l2->val + carry;
		}
		else if (l2 == NULL) {
			num = l1->val + carry;
		}
		else {
			num = l1->val+ l2->val + carry;
		}
		
		
		if(num > 9) {
			carry = 1;
			num %= 10;
		}
		else 
        {
			carry = 0;
		}
		temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->val = num;
        temp->next = NULL;
		if(c==1) 
        {
			c++;
			ListNodelist = temp;
			t = temp;
		}
        else
        {
			t->next = temp;
			temp->next = NULL;
			t = temp;
		}
		if(l1!=NULL) {
			l1 = l1->next;
		}
		if(l2 != NULL) {
			l2 = l2->next;
		}		
	}
	return ListNodelist;
}

int main()
{
    struct Node *first1 = NULL;
    struct Node *first2 = NULL;

    InsertLastSLL(&first1,2);
    InsertLastSLL(&first1,9);
    //InsertLastSLL(&first1,9);
   // InsertLastSLL(&first1,9);
    //InsertLastSLL(&first1,5);

    InsertLastSLL(&first2,4);
    InsertLastSLL(&first2,9);
    InsertLastSLL(&first2,9);
    InsertLastSLL(&first2,9);

    struct Node* ret = addTwoNum(first1,first2);

    DisplaySLL(ret);

    return 0;
}