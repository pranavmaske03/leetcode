#include<iostream>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) 
        {
            unordered_map<int,int> map;
            int prefixSum = 0,count = 0;    

            for(int i = 0; i < nums.size(); i++)
            {
                prefixSum += nums[i];
                if(prefixSum == goal) count++;
                if(map.find(prefixSum - goal) != map.end())
                {
                    count += map[prefixSum - goal];
                }
                map[prefixSum]++;
            }
            return count;
        }

        // Another approach
        private:
            int helper(vector<int>& nums, int goal) 
            {
                int sum = 0,left = 0, res = 0;

                if (goal < 0) return 0;
                for(int right = 0; right < nums.size(); right++) 
                {
                    sum += nums[right];
                    while(sum > goal)
                    {
                        sum -= nums[left++];
                    }
                    res += (right - left) + 1;
                }
                return res;
            }
        public:
            int numSubarraysWithSum1(vector<int>& nums, int goal) 
            {
                return helper(nums,goal) - helper(nums,goal - 1);
            }
};

int main()
{

    return 0;
}