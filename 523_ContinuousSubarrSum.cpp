#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool checkSubarraySum(vector<int>& nums, int k) 
        {
            int left = 0,prefixSum = 0;
            unordered_map<int,int> mp;
            mp[0] = -1;
            
            for(int right = 0; right < nums.size(); right++)
            {
                prefixSum += nums[right];
                if(mp.find(prefixSum % k) != mp.end()) {
                    if(right - mp[prefixSum % k] >= 2) return true;
                } else {
                    mp[prefixSum % k] = right;  
                }
            }
            return false;
        }
};

int main()
{

    return 0;
}