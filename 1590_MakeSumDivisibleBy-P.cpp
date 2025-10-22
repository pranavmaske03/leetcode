#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int minSubarray(vector<int>& nums, int p) 
        {
            unordered_map<int, int> mp;
            long long totalSum = 0,prefix = 0;
            int min_len = nums.size();

            mp[0] = -1;

            for (int num : nums) {
                totalSum += num;
            }

            int target = totalSum % p;
            if (target == 0) return 0;

            for (int i = 0; i < nums.size(); i++) 
            {
                prefix = (prefix + nums[i]) % p;
                int needed = (prefix - target + p) % p;

                if (mp.find(needed) != mp.end()) {
                    min_len = min(min_len, i - mp[needed]);
                }
                mp[prefix] = i; 
            }

            return (min_len == nums.size()) ? -1 : min_len;
        }
};


int main()
{
    vector<int> nums{8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2};
    Solution obj;
    cout<<obj.minSubarray(nums,148)<<endl;

    return 0;
}