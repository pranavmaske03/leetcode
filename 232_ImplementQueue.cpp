#include<iostream>
using namespace std;

class MyQueue {
public:
    int *arr;
    int rear;
    int front;
    MyQueue() 
    {
        arr = new int[100];
        rear = 0;
        front = 0;
    }
    
    void push(int x) 
    {
        arr[rear++] = x;
    }
    
    int pop() 
    {
        int no = arr[front++];
        return no;
    }
    
    int peek() 
    {
        int no = arr[front];
        return no;    
    }
    
    bool empty() 
    {
        if(front == rear)    
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