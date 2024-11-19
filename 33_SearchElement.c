#include<stdio.h>

int search(int* nums, int numsSize, int target) 
{
    int iPos = -1;
    for(int i = 0; i < numsSize; i++)    
    {
        if(nums[i] == target)
        {
            iPos = i;
            break;
        }
    }
    return iPos;
}

int main()
{


    return 0;
}