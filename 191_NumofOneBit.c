#include<stdio.h>

int hammingWeight(int n) 
{
    int count = 0,iDigit = 0;
    while(n != 0)       
    {
        iDigit = n % 2;
        if(iDigit == 1)
        {
            ++count;
        }
        n = n / 2;
    }
    return count;
}

int main()
{
    
    printf("%d\n",hammingWeight(2147483645));

    return 0;
}