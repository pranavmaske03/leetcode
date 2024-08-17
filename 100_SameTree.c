#include<stdio.h>
#include"LinkedList1.h"
#include<stdbool.h>
    
bool isSameTree(PNODE p, PNODE q) 
{
    bool flag1 = false;
    bool flag2 = false;

    if(p == NULL && q == NULL)
    {
        return true;
    }
    if(((p != NULL) && (q == NULL)) || ((p == NULL) && (q != NULL)) || (p->data != q->data))
    {
        return false;
    }
    if((p != NULL) && (q != NULL))
    {
        flag1 = isSameTree(p->lchild,q->lchild);
        printf("p->data : %d\tq->data : %d\n",p->data,q->data);
        flag2 = isSameTree(p->rchild,q->rchild);  
    }
    return flag1 & flag2;
}

int main()
{
    PNODE first1 = NULL;
    PNODE first2 = NULL;
    bool bRet = false;

    Insert(&first1,2);
    Insert(&first1,1);
    Insert(&first1,3);
    
    Insert(&first2,2);
    Insert(&first2,3);
    Insert(&first2,1);
    
    //Inorder(first1);
    //Inorder(first2);

    bRet = isSameTree(first1,first2);  
    if(bRet == true)
    {
        printf("both tree are same\n");
    }
    else
    {
        printf("both tree are not same\n");
    }
}