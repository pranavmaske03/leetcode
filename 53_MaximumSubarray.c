#include<stdio.h>

int maxSubArray(int* nums, int numsSize) 
{
    int max_sum = nums[0];
    int sum = 0;

    for(int i = 1; i < numsSize; i++)
    {
        if(sum < 0)
        {
            if(nums[i] > sum) sum = nums[i];
        }
        else
        {
           sum += nums[i];
        }
        max_sum = max_sum < sum ? sum : max_sum;
    }
    return max_sum;
}

int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int ret = maxSubArray(arr,9);

    printf("%d\n",ret);

    return 0;
}