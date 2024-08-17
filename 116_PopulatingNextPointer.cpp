#include<iostream>
using namespace std;

struct Node 
{
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

void Insert(struct Node** Head,int no)
{
    struct Node *temp = *Head;
    struct Node *newn = NULL;
    newn = (struct Node*)malloc(sizeof(struct Node));

    newn->val = no;
    newn->right = NULL;
    newn->left = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(1)
        {
            if(temp->val == no)
            {
                printf("Duplicate element : Unable to insert \n");
                free(newn);
                break;
            }
            else if(temp->val > no)
            {
                if(temp->left == NULL)
                {
                    temp->left = newn;
                    break;
                }
                temp = temp->left;
            }
            else if(temp->val < no)
            {
                if(temp->right == NULL)
                {
                    temp->right = newn;
                    break;
                }
                temp = temp->right;
            }
        }
    }
}

void Preorder(struct Node* Head)
{
    if(Head != NULL)
    {
        printf("%d\t",Head->val);
        Preorder(Head->left);
        Preorder(Head->right);
    }
}

void Display(struct Node *Head)
{
    while(Head != NULL)
    {
        cout<<"|"<<Head->val<<"|-> ";
        Head = Head->next;    
    }
    cout<<"\n";
}

class Solution
{
    public:
        Node* connect(Node* root) 
        {
            if (root == NULL) return 0;
    
            struct Node* queue[8000]; 
            int front = 0, rear = 0;

            int depth = 0;
            queue[rear++] = root;
            root->next = NULL;

            while (front < rear)
            {
                int tmp = rear - front;
                int c = -1;
                for (int i = 1; i <= tmp; i++)
                {
                    struct Node *tmp_node = queue[front++];
                
                    if (tmp_node->left != NULL){
                        queue[rear++] = tmp_node->left;
                        if(c != -1)
                        {
                            queue[rear-2]->next = queue[rear-1];
                        }
                        c++;
                    }
                    if (tmp_node->right != NULL){
                        queue[rear++] = tmp_node->right;
                        queue[rear-2]->next = queue[rear-1];
                    }
                    if(i == tmp)
                    {
                        tmp_node = queue[rear-1];
                        //cout<<tmp_node->val<<"\n";
                        tmp_node->next = NULL;
                        Display(queue[front]);
                    }
                }
            }         
            return root;
        }   
};

int main()
{
    struct Node *first = NULL;

    Insert(&first,10);
    Insert(&first,8);
    Insert(&first,9);
    Insert(&first,7);
    Insert(&first,12);
    Insert(&first,11);
    Insert(&first,13);

    //Preorder(first);

    Solution obj;
    obj.connect(first);
    return 0;
}