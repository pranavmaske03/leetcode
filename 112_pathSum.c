#include"LinkedList.h"

bool helper(struct NodeBST *root,int targetSum,int sum)
{
    if (root == NULL) return false;

    sum += root->data;

    if(root->lchild == NULL && root->rchild == NULL && sum == targetSum) return true;

    return helper(root->lchild,targetSum,sum) ||  helper(root->rchild,targetSum,sum);
}

bool hasPathSum(struct NodeBST* root, int targetSum) 
{   
    if(root == NULL) return false;
    return helper(root,targetSum,0);
}

int main()
{
    struct NodeBST* first1 = NULL;
    bool bRet = false;

    Insert(&first1,22);
    Insert(&first1,11);
    Insert(&first1,33);
    Insert(&first1,32);
    Insert(&first1,13);
    Insert(&first1,1);
    Insert(&first1,45);
    Insert(&first1,50);
    
    Preorder(first1);
    printf("\n");

    bRet = hasPathSum(first1,100);
    if(bRet == true)
    {
        printf("Available \n");
    }
    else
    {
        printf("Not available \n");
    }

    return 0;
}