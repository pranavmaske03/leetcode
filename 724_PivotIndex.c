#include<stdio.h>

int pivotIndex(int* nums, int numsSize) 
{
    int total_sum = 0;
    int left_sum = 0;
    int pivot = -1;
    
    for(int i = 0; i < numsSize; i++)
    {
       total_sum += nums[i];
    }
    
    for(int i = 0; i < numsSize; i++)
    {
        if(left_sum == total_sum - left_sum - nums[i])
        {
            pivot = i;
            break;
        }
        left_sum += nums[i];
    }
    return pivot;
}

int main()
{
    int arr[] = {-1,-1,0,0,-1,-1};
    int ret = pivotIndex(arr,6);

    printf("pivot = %d\n",ret);

    return 0;
}