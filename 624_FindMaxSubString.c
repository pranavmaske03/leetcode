#include<stdio.h>

int findLengthOfLCIS(int* nums, int numsSize) 
{
    int curr_max = 1;
    int max = 0;

    for(int i = 1; i < numsSize; i++)    
    {
        if(nums[i] > nums[i-1])
        {
            curr_max++;
        }
        else
        {
            if(max < curr_max)
            {
                max = curr_max;
            }
            curr_max = 1;
        }
    }
    return max > curr_max ? max : curr_max;
}

int main()
{
    int arr[] = {1,3,5,4,7};

    return 0;
}