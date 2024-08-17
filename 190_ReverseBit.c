#include<stdio.h>

int reverseBit(int n)
{
    unsigned int size = sizeof(n) * 8;
    unsigned int result = 0;

    for(int i = 0; i < 8; i++)
    {
        result = result << 1;
        result = result | (n & 1)    ;
        n = n >> 1;
    }
    printf("%d\n",result);
    return result;
}

int main()
{
    int ret = reverseBit(123);

    printf("Reverse bit number is : %d\n");

    return 0;
}