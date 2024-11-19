#include<stdio.h>

int majorityElement(int* nums, int numsSize) 
{
    int candidate = -1,count = 0;

    for(int i = 0; i < numsSize; i++)    
    {
        if(count == 0)
        {
            candidate = nums[i];
            count = 1;
        }
        else if(candidate == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }      
    }
    return candidate;
}

int main()
{
    int Arr[] = {2,1,2,1,2,1,2};

    int ret = majorityElement(Arr,7);
    printf("%d\n",ret);

    return 0;
}