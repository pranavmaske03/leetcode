#include<stdio.h>
#include<stdbool.h>

bool check(int* nums, int numsSize) 
{
    int count = 0;

    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] < nums[i-1])
        {
            count++;
        }
    }
    if(nums[0] < nums[numsSize-1])
    {
        count++;
    }
    return count <= 1;
}

int main()
{
    int arr[] = {3,4,5,1,2};
    printf("%d\n",check(arr,4));

    return 0;
}