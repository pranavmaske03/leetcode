#include<stdio.h>
#include"LinkedList1.h"
#include<stdint.h>

int maxDepth(PNODE root) 
{
    if(!root) 
    {
        return 0;
    }
    else 
    {
        int left = maxDepth(root->lchild);
        int right = maxDepth(root->rchild);
        printf("left = %d\t right = %d\t data = %d\n",left,right    ,root->data);
        return (left > right ? left : right) + 1;
    }
}

int maxDepth1(PNODE root) 
{
    if (root == NULL) return 0;
    
    PNODE queue[8000]; 
    uint16_t front = 0, rear = 0;

    uint16_t depth = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        uint16_t tmp = rear - front;
        //printf("tmp = %d\t reare = %d\t frone = %d\n",tmp,rear,front);
        for (uint16_t i = 0; i < tmp; i++)
        {
            PNODE tmp_node = queue[front++];
        
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

    Insert(&first1,45);
    Insert(&first1,23);
    Insert(&first1,24);
    Insert(&first1,46);
    Insert(&first1,11);
    Insert(&first1,9);

    //Inorder(first1);
    ret = maxDepth1(first1);
    printf("maximum depth of the tree is : %d\n",ret);
    return 0;
}