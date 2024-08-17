#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int removeDuplicates(int* nums, int numsSize) 
{
    int i = 0,j = 0,k = 0;

    for(i = 0; i < numsSize-1; i++)
    {
        if(nums[i] == nums[i+1])
        {
            continue;
        }
        else
        {
            nums[k] = nums[i];
            k++;
        }
    }
    if(i == numsSize-1)
    {
        nums[k] = nums[i];
        k++;
    }
    
    return k;
}

int main()
{
    int Arr[] = {1,1,1,2,2,3,3,4,4,5,5,6,6,7};

    int ret = removeDuplicates(Arr,14);

    printf("%d\n",ret);

    return 0;
}