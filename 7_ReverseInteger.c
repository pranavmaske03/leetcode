#include<stdio.h>

int reverse(int x)
{
    int iDigit = 0,result = 0;

    while(x != 0)
    {
        iDigit = x % 10;
        result = (result * 10) + iDigit;
        printf("result = %d\n",result);
        x = x / 10;
    }
    return result;
}

int main()
{
    int ret = reverse(1534236469);

    printf("%d\n",ret);

    return 0;
}