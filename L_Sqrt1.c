#include<stdio.h>



int main()
{
    int value = 0;

    printf("Enter number :\n");
    scanf("%d",&value);

    int ret = mySqrt(value);
    printf("Square root of the %d is : %d\n",value,ret);

    return 0;
}