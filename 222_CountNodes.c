#include<stdio.h>
#include"LinkedList.h"

int countNodes(struct NodeBST* root) 
{
    if (root == NULL) return 0;
    
    struct NodeBST* arr[50000];
    struct NodeBST* tmp_node = NULL;
    int rear = 0,front = 0;

    arr[rear++] = root;

    while(front < rear)
    {
        int tmp = rear - front;

        for(int i = 0; i < tmp; i++)
        {
            tmp_node = arr[front++];
            if (tmp_node->lchild == NULL && tmp_node->rchild == NULL)
            {
                continue;
            }
            if(tmp_node->lchild != NULL)
            {
                arr[rear++] = tmp_node->lchild;
            }
            if(tmp_node->rchild != NULL)
            {
                arr[rear++] = tmp_node->rchild;
            }
        }
    }
    return rear;
}

int main()
{
     struct NodeBST* first = NULL;
    int ret = 0;

    Insert(&first,1);
    Insert(&first,2);
    Insert(&first,9);
    Insert(&first,3);
    Insert(&first,5);
    Insert(&first,6);
    //Preorder(first);
    ret = countNodes(first);
    printf("%d\n",ret);
    return 0;
}