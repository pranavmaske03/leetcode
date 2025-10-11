#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int subarraysDivByK(vector<int>& nums, int k) 
        {
            vector<int> freq(k,0);
            int prefixSum = 0,count = 0;

            // base case for empty prefix 
            freq[0] = 1;

            for(int i = 0; i < nums.size(); i++)
            {
                prefixSum += nums[i];
                // normalize reminder (imp if rem is -ve)
                int rem = (prefixSum % k + k) % k;

                // add the subarray count
                count += freq[rem];
                
                // increase the frequency of the remainder
                freq[rem]++;
            }
            return count;
        }
};

int main()
{

    return 0;
}