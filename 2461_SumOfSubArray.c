#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

int chain[100001] = {0};
int duplicate = 0;
long long sum = 0;

void Add(int val)
{
    chain[val]++;
    sum += val;
    if(chain[val] == 2)
    {
        duplicate++;
    }
}

void Remove(int val)
{
    chain[val]--;
    sum -= val;
    if(chain[val] == 1)
    {
        duplicate--;
    }
}

int Max(int num1,int num2) 
{
    return num1 > num2 ? num1 : num2;
}

long long maximumSubarraySum(int* nums, int numsSize, int k) 
{
    long long max_sum = INT_MIN;

    for(int i = 0; i < k; i++)
    {
        Add(nums[i]);
    }
    if(!duplicate) {
        max_sum = Max(sum,max_sum);
    }

    for(int right = k,left = 0; right < numsSize; right++,left++) 
    {
        Add(nums[right]);
        Remove(nums[left]);

        if(!duplicate) {
            max_sum = Max(sum,max_sum);
        }
    }
    return max_sum == INT_MIN ? 0 : max_sum;
}

int main()
{
    int arr[20] = {1,2,2};
    
    printf("%lld\n",maximumSubarraySum(arr,3,2));

    return 0;
}