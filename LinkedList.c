#include"LinkedList.h"

int main()
{
    struct NodeBST *first = NULL;

    Insert(&first,86);
    Insert(&first,89);
    Insert(&first,96);
    Insert(&first,56);
    Insert(&first,36);
    Insert(&first,50);

    Inorder(first);
}