#include<stdio.h>
#include<stdlib.h>

void Counting_Sort(int* nums, int numsSize) 
{
    int i = 0,j = 0,min = 0,max = 0;
    for(i = 0; i < numsSize; i++)
    {
        min = min > nums[i] ? nums[i] : min;
        max = max < nums[i] ? nums[i] : max;
    }
    max -= min;
    int *output = calloc((++max),sizeof(int));
    for(int i = 0; i < numsSize; i++)
    {
        output[nums[i] - min]++;
    }
    int index = 0;
    for(int i = 0; i < max; i++)
    {
        while(output[i] > 0)
        {
            nums[index] = i;
            nums[index++] += min;
            output[i]--;
        }
    }
    free(output);
}

int* sortArray(int* nums, int numsSize, int* returnSize) 
{
    Counting_Sort(nums, numsSize);
    *returnSize = numsSize; 
    return nums;
}

int main()
{
    int arr[] = {-5,-7,-3,12,90,34,56,-89,5,2,3,1};

    int size = 0;
    int *ret = sortArray(arr,12,&size);
    for(int i = 0; i < size; i++)
    {
        printf("%d\t",ret[i]);
    }

    return 0;
}