#include<iostream>
#include<unordered_map>
using namespace std;

class Solution 
{
public:
    int longestSubarray(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        int prefixSum = 0, maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            if (prefixSum == k) maxLen = i + 1;

            if (mp.find(prefixSum - k) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefixSum - k]);
            }

            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }
        return maxLen;
    }
};


int main()
{

    return 0;
}