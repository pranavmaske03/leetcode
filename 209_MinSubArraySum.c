#include<stdio.h>
#include<limits.h>

int min(const void *a,const void *b)
{
    return (a < b) ? a : b;
}

int minSubArrayLen(int target, int* nums, int numsSize) {
    
    if(nums == NULL || numsSize < 1)
    {
        return 0;
    }

    int result = INT_MAX;
    int currentSum  = 0;

    int left =  0;
    int right = 0;

    while(right < numsSize)
    {
        currentSum += nums[right];

        while(currentSum >= target)
        {
            result = min(result, right - left + 1);
            currentSum-= nums[left];
            left++;
        }        
        right++;
    }
       return (result == INT_MAX) ? 0 : result;
}

int main()
{
    int arr[] = {2,3,1,2,4,3};

    printf("%d\n",minSubArrayLen(7,arr,6));

    return 0;
}