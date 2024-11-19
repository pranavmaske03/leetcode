#include<stdio.h>
#include"LinkedList1.h"
#include<stdint.h>

// uint16_t is unsigned short integer 2 bytes range(0 - 65535))

int minDepth(PNODE root) 
{
    if (root == NULL) return 0;
    
    PNODE queue[8000]; 
    uint16_t front = 0, rear = 0;

    // If not null, starts from 1
    uint16_t depth = 1;
    queue[rear++] = root;

    while (front < rear)
    {
        uint16_t tmp = rear - front;

        for (uint16_t i = 0; i < tmp; i++)
        {
            PNODE tmp_node = queue[front++];
            
            if (tmp_node->lchild == NULL && tmp_node->rchild == NULL){
                return depth;
            }
            if (tmp_node->lchild != NULL){
                queue[rear++] = tmp_node->lchild;
            }
            if (tmp_node->rchild != NULL){
                queue[rear++] = tmp_node->rchild;
            }
        }
        depth++;
    }
    return depth;
}

int main()
{
    PNODE first1 = NULL;
    int ret = 0;

    Insert(&first1,50);
    Insert(&first1,45);
    Insert(&first1,35);
    Insert(&first1,25);
    Insert(&first1,48);
    Insert(&first1,38);
    Insert(&first1,28);
    Insert(&first1,55);
    Insert(&first1,58);
    Insert(&first1,65);
    //Insert(&first1,5);

    Inorder(first1);
    ret = minDepth(first1);
    printf("minimum depth of the tree is : %d\n",ret);
    return 0;
}