#include<iostream>
#include<vector>
#include<bits/c++.h>
using namespace std;

class Solution 
{
    public:
        int maxSubArray(vector<int>& nums) 
        {
            int sum = 0,maxSum = INT_MIN;

            for(int i = 0; i < nums.size(); i++)    
            {
                sum = sum + nums[i];
                maxSum = max(maxSum,sum);
                if(sum < 0) sum = 0;
            }
            return maxSum;
        }

        int maxSubArray1(vector<int>& nums)
        {
            int currSum = nums[0];
            int maxSum = nums[0];

            for(int i = 1; i < nums.size(); i++)
            {
                currSum = max(nums[i],currSum + nums[i]);
                maxSum = max(maxSum,currSum);
            }
            return maxSum;
        }
};

int main() 
{
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    Solution obj;
    obj.maxSubArray(arr);

    return 0;
}
