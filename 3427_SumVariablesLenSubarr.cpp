#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int subarraySum(vector<int>& nums) 
        {
            vector<int> prefix(nums.size() + 1, 0);
            int totalSum = 0;

            for (int i = 0; i < nums.size(); i++) {
                prefix[i + 1] = prefix[i] + nums[i];
            }

            for(int i = 0; i < nums.size(); i++) {
                int start = max(0, i - nums[i]);
                totalSum += prefix[i + 1] - prefix[start];
            }

            return totalSum;
        }
};

int main()
{

    return 0;
}