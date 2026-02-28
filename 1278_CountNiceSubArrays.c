#include<stdio.h>


int numberOfSubarrays(int* nums, int numsSize, int k) 
{
    int left = 0, oddCount = 0, subCount = 0, res = 0;

    for(int right = 0; right < numsSize; right++) {
        if(nums[right] % 2 != 0) {
            oddCount++;
            subCount = 0;
        }

        while(oddCount == k) {
            subCount++;
            if(nums[left++] % 2 != 0) oddCount--;
        }
        res += subCount;
    }
    return res;
}

int main()
{
    return 0;
}