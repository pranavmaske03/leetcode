#include<stdio.h>

int missingNumber(int* nums, int numsSize) 
{
    int sum1 = 0,sum2 = 0,iCnt = 0;    

    for(int i = 0; i < numsSize; i++)
    {
        sum1 = sum1 + nums[i];
        sum2 = sum2 + ++iCnt;
    }
    return sum2 - sum1;
}

int main()
{
    int arr[20] = {1,2,3,5};

    int ret = missingNumber(arr);
    printf("%d\n",ret);

    return 0;
}