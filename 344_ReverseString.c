#include<stdio.h>

void reverseString(char* s, int sSize) 
{
    int start = 0,end = sSize-1;
    char ch = '\0';
    while(start < end)    
    {
        ch = s[start];
        s[start] = s[end];
        s[end] = ch;
        start++;
        end--;
    }
}

int main()
{
    char Arr[20] = {"Hello"};

    reverseString(Arr,5);
    printf("%s\n",Arr);

    return 0;
}