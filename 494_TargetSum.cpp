#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<vector<int>> memo;
        int offset;

        int solver(vector<int>& nums, int target, int currSum, int i) {
            if(i == nums.size())
                return currSum == target ? 1 : 0;

            int key = currSum + offset;
            if(memo[i][key] != -1)
                return memo[i][key];

            int add = solver(nums, target, currSum + nums[i], i + 1);
            int sub = solver(nums, target, currSum - nums[i], i + 1);

            return memo[i][key] = add + sub;
        }

        int findTargetSumWays(vector<int>& nums, int target) {
            int totalSum = 0;
            for(int num : nums) totalSum += num;

            offset = totalSum;
            memo.assign(nums.size(), vector<int>(2 * totalSum + 1, -1));

            return solver(nums, target, 0, 0);
        }
};


int main()
{}