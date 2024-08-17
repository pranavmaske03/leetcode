#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int maximumGap(int* nums, int numsSize) 
{
    if(numsSize < 2) return 0;
    int gap = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for(int i = 1; i < numsSize; i++)
    {
        if(gap < (nums[i] - nums[i-1])) 
        {
            gap = (nums[i] - nums[i-1]);
        }
    }
    return gap;
}

int main()
{
    int arr[] = {1,10000000};
    
    printf("%d\t",maximumGap(arr,2));

    return 0;
}