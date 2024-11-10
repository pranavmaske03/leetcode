#include"LinkedList.h"

int dfsHeight(struct NodeBST* root)
{
    if(root == NULL) return 0;

    int leftHeight = dfsHeight(root->lchild);
    if(leftHeight == -1) return -1;
    int rightHeight = dfsHeight(root->rchild);
    if(rightHeight == -1) return -1;

    if(abs(leftHeight - rightHeight) > 1) return -1;
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isBalanced(struct NodeBST* root) 
{
    return dfsHeight(root) != -1;
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
    Insert(&first1,48);
    
    Inorder(first1);
    printf("\n");
    Preorder(first1);
    printf("\n");
    Postorder(first1);
    printf("\n");

    bRet = isBalanced(first1);  
    if(bRet == true)
    {
        printf("Tree is balanced\n");
    }
    else
    {
        printf("Tree is not balanced\n\n");
    }

    return 0;
}