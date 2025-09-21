#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        int subarraySum(vector<int>& nums, int k) 
        {
            unordered_map<int,int> mp;
            int prefixSum = 0,count = 0;

            for(int i = 0; i < nums.size(); i++)
            {
                prefixSum += nums[i];
                if(prefixSum == k) count++;
                if(mp.find(prefixSum - k) != mp.end()) {
                    count += mp[prefixSum - k];
                }
                mp[prefixSum]++;
            }
            return count;
        }
};

int main()
{

    return 0;
}