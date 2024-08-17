#include<stdio.h>
#include<stdbool.h>

bool isPowerOfTwo(int n) 
{   
    return n < 1 ? false : (n & (n - 1)) == 0 ? true : false;
}

int main()
{
    bool bRet = isPowerOfTwo(16);
    if(bRet == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    printf("%d\n",16&15);
    return 0;
}