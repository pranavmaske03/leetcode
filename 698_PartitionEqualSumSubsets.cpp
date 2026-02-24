#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool backtrack(vector<int>& nums, vector<int>& subsetSum, int start, int& k,
                   int& target) {
        if (start == nums.size())
            return true;

        for (int i = 0; i < k; i++) {
            if (subsetSum[i] + nums[start] > target)
                continue;

            subsetSum[i] += nums[start];
            if (backtrack(nums, subsetSum, start + 1, k, target))
                return true;
            subsetSum[i] -= nums[start];

            if(subsetSum[i] == 0)
                break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = 0;
        vector<int> subsetSum(k, 0);

        for (int& num : nums) {
            totalSum += num;
        }
        int target = totalSum / k;
        sort(nums.begin(), nums.end(), std::greater<int>());

        if (totalSum % k != 0 || nums[0] > target)
            return false;

        return backtrack(nums, subsetSum, 0, k, target);
    }
};

int main()
{
    return 0;
}