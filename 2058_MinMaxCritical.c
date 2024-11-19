#include"LinkedList.h"
#include<limits.h>

int* nodesBetweenCriticalPoints(struct Node* head) 
{
    int iCnt = 1,n = -1,m = -1;
    int *Arr = malloc(sizeof(int) * 2);
    Arr[0] = INT_MAX;
    Arr[1] = -1;

    while(head->next->next != NULL)
    {   
        if((((head->data) < (head->next->data))&&((head->next->data) > (head->next->next->data)))||(((head->data) > (head->next->data))&&((head->next->data) < (head->next->next->data))))
        {   
            if(m == -1)
            {
                m = iCnt;
            }
            if(n != -1)
            {
                if(Arr[0] > iCnt - n)
                {
                    Arr[0] = iCnt - n;
                }
            }
            n = iCnt;        
        }
        iCnt++;
        head = head->next;
    }
    if(Arr[0] == INT_MAX)
    {
        Arr[0] = -1;
    }
    if(n != m)
    {
        Arr[1] = n - m;
    }
    return Arr;
}

int main()
{
    struct Node *first1 = NULL;

    InsertLastSLL(&first1,6);
    InsertLastSLL(&first1,8);
    InsertLastSLL(&first1,4);
    InsertLastSLL(&first1,1);
    InsertLastSLL(&first1,9);
    InsertLastSLL(&first1,6);
    InsertLastSLL(&first1,6);
    InsertLastSLL(&first1,10);
    InsertLastSLL(&first1,6);    

    //6,8,4,1,9,6,6,10,6

    int *ret = nodesBetweenCriticalPoints(first1);

    printf("%d\t%d\n",ret[0],ret[1]);

    return 0;
}