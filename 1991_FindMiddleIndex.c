#include<stdio.h>

int findMiddleIndex(int* nums, int numsSize) 
{
    int total_sum = 0,left_sum = 0;
    int middle_idx = -1;

    for(int i = 0; i < numsSize; i++)
    {
        total_sum += nums[i];
    }

    for(int i = 0; i < numsSize; i++)
    {
        if(left_sum == total_sum - left_sum - nums[i]) {
            middle_idx = i;
            break;
        }
        left_sum += nums[i];
    }
    return middle_idx;
}

int main()
{
    int arr[] = {2,3,-1,8,4};
    int size = 5;

    printf("%d\n",findMiddleIndex(arr,size));
    return 0;
}