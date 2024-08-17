#include<stdio.h>
#include<stdlib.h>

int findKthLargest(int* nums, int numsSize, int k) 
{
    int max = 0,min = 0;
    for(int i = 0; i < numsSize; i++)
    {
        max = max < nums[i] ? nums[i] : max;
        min = min > nums[i] ? nums[i] : min;
    }
    max -= min;
    int *k_largest = calloc((++max),sizeof(int));
    for(int i = 0; i < numsSize; i++)
    {
        k_largest[nums[i] - min]++;
    }
    for(int i = max-1; i >= 0; i--)
    {
        while(k_largest[i] > 0 && k > 0)
        {
            max = i + min;
            k_largest[i]--;
            k--;
        }
        if(k == 0) break;
    }
    free(k_largest);
    return max;
}
/*
    for (int i = max - min; i >= 0; --i) 
    {
        k -= k_largest[i];
        
        if (k <= 0)
            return i + min;
    }
*/
int main()
{
    int arr[] = {3,2,1,5,6,4};

    printf("%d\n",findKthLargest(arr,6,2));

    return 0;
}