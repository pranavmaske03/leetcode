#include<stdio.h>
#include<stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) 
{
    int *ans = (int*)malloc((2*numsSize) * sizeof(int));

    for(int i = 0; i < numsSize; i++)
    {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];
    }
    *returnSize = (2*numsSize);
    return ans;      
}

int main()
{
    int arr[20] = {1,2,3,4,5};
    int val = 0;

    int *ret = getConcatenation(arr,5,&val);

    for(int i = 0; i < 10; i++)
    {
        printf("%d\t",ret[i]);
    }

    return 0;
}