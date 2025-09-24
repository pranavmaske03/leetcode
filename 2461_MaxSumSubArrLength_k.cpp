#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution 
{
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) 
        {
            unordered_map<int,int> map;
            int left = 0;
            long long sum = 0,maxSum = 0;

            for(int right = 0; right < nums.size(); right++)
            {
                map[nums[right]]++;
                sum += nums[right];

                while(map[nums[right]] > 1) {
                    map[nums[left]]--;
                    sum -= nums[left++];
                }

                while(right - left + 1 > k) {
                    map[nums[left]]--;
                    sum -= nums[left++];
                }
                if(right - left + 1 == k) {
                    maxSum = max(maxSum,sum);
                }
            }
            return maxSum;
        }
};

int main()
{

    return 0;
}