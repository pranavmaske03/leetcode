#include"LinkedList.h"

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode *create_node()
{
    struct TreeNode *newn = malloc(sizeof(struct Node));
    newn->left = NULL;
    newn->right = NULL;
    newn->val = 0;
    return newn;
}
void Inorder1(struct TreeNode* Head)
{
    if(Head != NULL)
    {
         printf("%d\t",Head->val);
        Inorder1(Head->right);
        Inorder1(Head->left);
    }
}
struct TreeNode* createBinaryTree(int (*d)[50], int Size, int descriptionsColSize) 
{
    struct TreeNode *root = NULL,*tmp_node = NULL;
    for(int i = 0; i < Size; i++)
    {
        if(root == NULL)
        {
            struct TreeNode *newn = create_node();
            newn->val = d[0][0];
            root = newn;
            if(d[0][2] == 1){
                struct TreeNode *newnode = create_node();
                newnode->val = d[0][1];
                newn->left = newnode;
            }
            else{
                struct TreeNode *newnode = create_node();
                newnode->val = d[0][1];
                newn->right = newnode;
            }
        }
        else if(root->val == d[i][0])
        {
            if(d[i][2] == 1) {
                struct TreeNode *newnode = create_node();
                newnode->val = d[i][1];
                root->left = newnode;
            }
            else{
                struct TreeNode *newnode = create_node();
                newnode->val = d[i][1];
                root->right = newnode;
            }
        }
        else if(root->val != d[i][0]){
            if(root->val == d[i][1]){
                struct TreeNode *newnode = create_node();
                newnode->val = d[i][0];
                if(d[i][2] == 1){
                    newnode->left = root;
                    root = newnode;
                }else{
                    newnode->right = root;
                    root = newnode;
                }
            }else if(root->right != NULL && root->right->val == d[i][0]){
                struct TreeNode *newnode = create_node();
                newnode->val = d[i][1];
                tmp_node = root->right;
                if(d[i][2] == 1){
                    tmp_node->left = newnode;
                }else{
                    tmp_node->right = newnode;
                }
            }else if(root->left != NULL && root->left->val == d[i][0]){
                struct TreeNode *newnode = create_node();
                newnode->val = d[i][1];
                tmp_node = root->left;
                if(d[i][2] == 1){
                    tmp_node->left = newnode;
                }else{
                    tmp_node->right = newnode;
                }
            }else {
               
            }
        }
    }
    Inorder1(root);
}

int main()
{
    int arr[50][50] = {{85,82,1},{74,85,1},{39,70,0},{82,38,1},{74,39,0},{39,13,1}};
    createBinaryTree(arr,6,3);//[[85,82,1],[74,85,1],[39,70,0],[82,38,1],[74,39,0],[39,13,1]]

    return 0;
}