#include"LinkedList.h"
#include<stdlib.h>

int getDecimalValue(struct Node* head) 
{
    int sum = 1,num = 0,c = -1;
    while(head != NULL)        
    {
        if(head->data == 0)
        {
            num = (num << 1);
        }
        else
        {
            num = (num << 1)+1;
        }
        head = head->next;
    }
    return num;
}

int main()
{
    struct Node* first = NULL;
    int ret = 0;

    InsertLastSLL(&first,1);
    InsertLastSLL(&first,0);
    InsertLastSLL(&first,1);
    InsertLastSLL(&first,0);
    //InsertLastSLL(&first,5);
    //InsertLastSLL(&first,6);
    //InsertLastSLL(&first,7);
    //DisplaySLL(first);

    ret = getDecimalValue(first);
    
    printf("%d\n",ret);

    return 0;
}