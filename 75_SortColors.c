#include<stdio.h>

void sortColors(int* nums, int numsSize)
{
    int count[3] = {0};
    int output[numsSize];
    
    for(int i = 0; i < numsSize; i++)
    {
        count[nums[i]]++;
    }
    for(int i = 1; i < 3; i++)
    {
        count[i] += count[i - 1];
    }
    for(int i = 0; i < numsSize; i++)
    {
        output[--count[nums[i]]] = nums[i];
    }
    for(int i = 0; i < numsSize; i++)
    {
        nums[i] = output[i];
    }
}
int main()
{
    int arr[] = {2,0,2,1,1,0};
    sortColors(arr,6);

    return 0;
}