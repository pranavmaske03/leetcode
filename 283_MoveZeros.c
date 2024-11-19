#include<stdio.h>


void moveZeroes(int* nums, int numsSize) 
{
    int j = 0,i = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
    }
    while(j < numsSize)
    {
        nums[j++] = 0;
    }
}

int main()
{

    return 0;
}