#include<stdio.h>

int i = 0;
int memo[30] = {0};
int fib(int n)
{

    printf("iteration = %d\n",++i);
    if(memo[n] != 0)
    {
        return memo[n];
    }
    if(n <= 1)
    {
        return n;
    }
    else
    {
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
    }
}

int main()
{
    // 2692537 - 59 = 2692478
    printf("%d",fib(30));

    return 0;
}