#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct NodeBST
{
    int data;
    struct NodeBST *rchild;
    struct NodeBST *lchild;
};

////////////////////////////////////////////////////////////////////////////////////////////
// Singly Linear LinkedList
///////////////////////////////////////////////////////////////////////////////////////////

void InsertFirstSLL(struct Node** Head,int iNo)
{
    struct Node* newn = NULL;
    newn = (struct Node*)malloc(sizeof(struct Node));
    newn->data = iNo;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLastSLL(struct Node** Head,int iNo)
{
    struct Node* temp = *Head;
    struct Node* newn = NULL;
    newn = (struct Node*)malloc(sizeof(struct Node));
    newn->data = iNo;
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

void DisplaySLL(struct Node* Head)
{
    printf("Elements of the linked List are : \n");
    
    while(Head != NULL)
    {
        printf("| %d |->",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int CountSLL(struct Node* Head)
{
    int iCount = 0;

     while(Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    return iCount;
}

void DeleteFirstSLL(struct Node** Head)
{
    struct Node* temp = *Head;

    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free(temp);
    }
}

void DeleteLastSLL(struct Node** Head)
{
    struct Node* temp = *Head;

    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPosSLL(struct Node** Head,int iNo,int iPos)
{
    int iLength = 0;
    int iCnt = 0;
    struct Node* temp = *Head;
    struct Node* newn = NULL;

    iLength = CountSLL(*Head);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid position \n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirstSLL(Head,iNo);
    }
    else if(iPos == iLength+1)
    {
        InsertLastSLL(Head,iNo);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn = (struct Node*)malloc(sizeof(struct Node));
        newn->next = NULL;
        newn->data = iNo;

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtposSLL(struct Node** Head,int iPos)
{
    int iLength = 0;
    int iCnt = 0;
    struct Node* temp = *Head;
    struct Node* tempX = NULL;

    iLength = CountSLL(*Head);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid position \n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirstSLL(Head);
    }
    else if(iPos == iLength)
    {
        DeleteLastSLL(Head);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;
        free(tempX);
    }
}

///////////////////////////////////////////////////////////////////////////
// Singly Circular LinkedList
///////////////////////////////////////////////////////////////////////////

void InsertFirstSCL(struct Node** Head,struct Node** Tail,int iNo)
{
    struct Node* newn = NULL;
    newn = (struct Node*)malloc(sizeof(struct Node));

    newn->next = NULL;
    newn->data = iNo;

    if(*Head == NULL && *Tail == NULL)
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
    (*Tail)->next = newn;
}

void InsertLastSCL(struct Node** Head,struct Node** Tail,int iNo)
{
    struct Node* newn = NULL;
    newn = (struct Node*)malloc(sizeof(struct Node));

    newn->next = NULL;
    newn->data = iNo;

    if(*Head == NULL && *Tail == NULL)
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        *Tail = newn;
    }
    (*Tail)->next = *Head;
}

void DisplaySCL(struct Node* Head,struct Node* Tail)
{
    printf("Elements of the linklist are : \n");

    if((Head != NULL) && (Tail != NULL))
    {
        do
        {
            printf("|%d|-> ",Head->data);
            Head = Head->next;
        }while(Head != Tail->next);
    }
    else
    {
        printf("Linklist is empty \n");
    }
    printf("\n");
}

int CountSCL(struct Node* Head,struct Node* Tail)
{
    int iCount = 0;

    if((Head != NULL) && (Tail != NULL))
    {
        do
        {
            iCount++;
            Head = Head->next;
        }while(Head != Tail->next);

        return iCount;
    }
    else
    {
        return 0;
    }
}

void DeleteFirstSCL(struct Node** Head,struct Node** Tail)
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        printf("LInklist is empty \n");
        return;
    }

    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Tail)->next);

        (*Tail)->next = *Head;
    }
}

void DeleteLastSCL(struct Node** Head,struct Node** Tail)
{
    struct Node* temp = *Head;

    if((*Head == NULL) && (*Tail == NULL))
    {
        printf("LInklist is empty \n");
        return;
    }

    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        while(temp->next != *Tail)
        {
            temp = temp->next;
        }
        free(temp->next);
        *Tail = temp;
        (*Tail)->next = *Head;
    }
}

void InsertAtPosSCL(struct Node** Head,struct Node** Tail,int iPos,int iNo)
{
    int iLength = 0;
    int iCnt = 0;
    struct Node* newn = NULL;
    struct Node* temp = *Head;
    
    iLength = CountSCL(*Head,*Tail);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position \n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirstSCL(Head,Tail,iNo);
    }
    else if(iPos == iLength+1)
    {
        InsertLastSCL(Head,Tail,iNo);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn = (struct Node*)malloc(sizeof(struct Node));
        newn->next = NULL;
        newn->data = iNo;

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPosSCL(struct Node** Head,struct Node** Tail,int iPos)
{
    int iLength = 0;
    int iCnt = 0;
    struct Node* temp = *Head;
    struct Node* tempX = NULL;
    
    iLength = CountSCL(*Head,*Tail);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position \n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirstSCL(Head,Tail);
    }
    else if(iPos == iLength)
    {
        DeleteLastSCL(Head,Tail);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;
        free(tempX);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Binary Search Tree
////////////////////////////////////////////////////////////////////////////////////////////

void Insert(struct NodeBST** Head,int no)
{
    struct NodeBST *temp = *Head;
    struct NodeBST *newn = NULL;
    newn = (struct NodeBST*)malloc(sizeof(struct NodeBST));

    newn->data = no;
    newn->rchild = NULL;
    newn->lchild = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(1)
        {
            if(temp->data == no)
            {
                printf("Duplicate element : Unable to insert \n");
                free(newn);
                break;
            }
            else if(temp->data > no)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(temp->data < no)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
        }
    }
}

void Preorder(struct NodeBST* Head)
{
    if(Head != NULL)
    {
        printf("%d\t",Head->data);
        Preorder(Head->lchild);
        Preorder(Head->rchild);
    }
}

void Postorder(struct NodeBST* Head)
{
    if(Head != NULL)
    {
        Preorder(Head->lchild);
        Preorder(Head->rchild);
        printf("%d\t",Head->data);
    }
}

void Inorder(struct NodeBST* Head)
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);
        printf("%d\t",Head->data);
        Inorder(Head->rchild);
    }
}

bool Search(struct NodeBST* Head,int iSearch)
{
    bool flag = false;

    if(Head == NULL)
    {
        printf("Tree is empty : \n");
        return flag;
    }

    while(Head != NULL)
    {
        if(Head->data == iSearch)
        {
            flag = true;
            break;
        }
        else if(Head->data > iSearch)
        {
            Head = Head->lchild;
        }
        else if(Head->data < iSearch)
        {
            Head = Head->rchild;
        }
    }
}

int CountNodes(struct NodeBST* Head)
{
    static int iCount = 0;

    if(Head != NULL)
    {
        iCount++;
        CountNodes(Head->lchild);
        CountNodes(Head->rchild);
    }
    return iCount;
}

int CountLeafNodes(struct NodeBST* Head)
{
    static int iCount = 0;

    if(Head != NULL)
    {
        if((Head->rchild == NULL) && (Head->lchild == NULL))
        {
            iCount++;
        }
        CountLeafNodes(Head->lchild);
        CountLeafNodes(Head->rchild);
    }
    return iCount;
}

int CountParentNodes(struct NodeBST* Head)
{
    static int iCount = 0;

    if(Head != NULL)
    {
        if((Head->lchild != NULL) || (Head->rchild != NULL))
        {
            iCount++;
        }
        CountParentNodes(Head->lchild);
        CountParentNodes(Head->rchild);
    }
    return iCount;
}