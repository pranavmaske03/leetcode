#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

long long maximumSubarraySum(int* nums, int numsSize, int k) 
{
    long long chain[100001] = {0};
    long long max_sum = INT_MIN, sum = 0;
    int left = 0;

    for(int right = 0; right < numsSize; right++) 
    {
        chain[nums[right]]++;
        sum += nums[right];

        while(chain[nums[right]] > 1) {
            chain[nums[left]]--;
            sum -= nums[left++];
        }

        while(right - left + 1 > k) {
            chain[nums[left]]--;
            sum -= nums[left++];
        }

        if(right - left + 1 == k) {
            max_sum = max_sum > sum ? max_sum : sum;
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