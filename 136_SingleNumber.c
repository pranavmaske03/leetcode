#include<stdio.h>
#include<stdbool.h>

//Each element in the array appears twice except for one element which appears only once.

int singleNumber(int* nums, int numsSize) 
{
    int i,result=0;
    for(i = 0; i < numsSize; i++)
    {
        result = result ^ nums[i];
        printf("%d\n",result);
    }
    return result;
}

int main()
{
    int Arr[10] = {1,1,3,5,4,4,3};

    int ret = singleNumber(Arr,7);
    printf("ans = %d\n",ret);

    return 0;
}