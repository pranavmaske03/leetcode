#include<stdio.h>

int passThePillow(int n, int time) 
{
    int k = 0, ans = 1, x = 1;
    while(k != time)
    {
        ans = ans + x;
        if(ans == n)
        {
            x = -1;
        }
        if(ans == 1)
        {
            x = 1;
        }
        k++;
    }
    return ans;
}

int passThePillow1(int n, int time) 
{
    if(time >= 2 * (n-1))
    {
        time = time % (2*(n-1));
    }
    if(time >= (n-1))
    {
        time = time - n+1;
        return n - time;
    }
    return time + 1;
}

int main()  
{

    int ret = passThePillow1(4,5);
    printf("pillow holder = %d\n",ret);

    return 0;
}