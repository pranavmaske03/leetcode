#include<stdio.h>

float mySqrt(int x) 
{
    unsigned long int start = 0,end = x,mid = 0;
    double square_root = 0.0,diff = 0.0;

    while(start <= end)
    {
        mid = start+(end - start) / 2;

        if(mid * mid == x)
        {
            square_root = mid;
            break;
        }
        if(mid * mid < x)
        {
            square_root = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    float increment = 0.1;
    for(int i = 1; i <= 3; i++)
    {
        while(square_root * square_root <= x)
        {
            square_root += increment;
        }
        square_root -= increment;
        increment = increment / 10;
    }
    return square_root;
}

/*
    int mySqrt(int x) 
{
    unsigned long int start = 0,end = x,mid = 0;
    int square_root = 0;
    
    if(x==0)
    {
        return 0;
    }
    if(x==1)
    {
    return 1;
    }

    while(start <= end)
    {
        mid = start+(end - start) / 2;

        if(mid <= x/mid)
        {
            square_root = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return square_root;
}
*/
int main()
{
    int value = 0;

    printf("Enter number :\n");
    scanf("%d",&value);

    float ret = mySqrt(value);
    printf("Square root of the %d is : %f\n",value,ret);

    return 0;
}