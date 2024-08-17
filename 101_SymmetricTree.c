#include<stdio.h>
#include"LinkedList1.h"
#include<stdbool.h>
#include<stdint.h>

bool isSymmetric(PNODE root) 
{
    if (root == NULL) return false;
    if ((root->lchild == NULL && root->rchild != NULL)) return false;
    if ((root->lchild != NULL && root->rchild == NULL)) return false;
    
    PNODE queue[8000]; 

    PNODE left_node = NULL;
    PNODE right_node = NULL;

    uint16_t front = 0, rear = 0,m = 0,n = 0;
    bool flag = true;

    queue[rear++] = root;

    while (front < rear)
    {
        uint16_t tmp = rear - front;
        m = front;
        n = rear-1;

        for (uint16_t i = 0; i < tmp; i++)
        {
            PNODE tmp_node = queue[front++];

            if(tmp_node->lchild != NULL)
            {
                queue[rear++] = tmp_node->lchild;
            }
            if(tmp_node->rchild != NULL)
            {
                queue[rear++] = tmp_node->rchild;
            }
        }
        //printf("m = %d\tn = %d\n",m,n);
        while(m < n)
        {
            left_node = queue[m++];
            right_node = queue[n--];

            if(left_node->data != right_node->data)
            {
                flag = false;
                break;
            }
            if((left_node->lchild == NULL) && (right_node->rchild != NULL) || (left_node->lchild != NULL) && (right_node->rchild == NULL))
            {
                flag = false;
                break;
            }
            if((left_node->rchild == NULL) && (right_node->lchild != NULL) || (left_node->rchild != NULL) && (right_node->lchild == NULL))
            {
                flag = false;
                break;
            }
            //printf("temp1->data = %d\ttemp2->data = %d\n",temp1->data,temp2->data);
        }
        if(flag == false)
        {
            break;
        }
    }
    return flag;
}

int main()
{
    PNODE first1 = NULL;
    bool ret = 0;

    Insert(&first1,50);
    Insert(&first1,45);
    Insert(&first1,35);
    Insert(&first1,30);
    Insert(&first1,55);
    Insert(&first1,53);
    Insert(&first1,65);

    //Inorder(first1);
    ret = isSymmetric(first1);
    if(ret == true)
    {
        printf("tree is symmetri \n");
    }
    else
    {
        printf("NOT symmetic\n");
    }
    return 0;
}

