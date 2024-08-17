#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int searchInsert(int* nums, int numsSize, int target) 
{
    int i = 0,j = 0,iPos = 0;

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] == target)
        {
            iPos = i;
            break;
        }
        else if(nums[i] > target)
        {
            iPos = i;
            break;
        }
    }
    if(i == numsSize)
    {
        iPos = i;
    }
    return iPos;
}

int main()
{
    int Arr[] = {1,3,5,6};

    int ret = searchInsert(Arr,4,7);

    printf("%d\n",ret);

    return 0;
}