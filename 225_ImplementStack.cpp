#include<iostream>
using namespace std;

class MyStack 
{
    public:
        int *arr;
        int rear;
        MyStack() 
        {
            arr = new int[100];
            rear = -1;
        }
        
        void push(int x) 
        {
            arr[++rear] = x;
        }
        
        int pop() 
        {
            int no = arr[rear--];
            return no;
        }
        
        int top() 
        {
            int no = arr[rear];
            return no;
        }
        
        bool empty() 
        {
            if(rear == -1)    
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

int main()
{


    return 0;
}