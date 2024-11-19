#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int removeElement(int* nums, int numsSize, int val) 
{
    int i = 0,j = 0;

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            nums[j++] = nums[i];
        }
    }
    return j;
}

int main()
{
    int Arr[] = {1,2,4,7,4,7,5,6,7,9};

    int ret = removeElement(Arr,10,7);

    printf("%d\n",ret);

    return 0;
}