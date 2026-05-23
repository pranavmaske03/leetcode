#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        vector<int> lenqavitor = nums;
        int n = nums.size();

        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int num : nums) {
            unordered_map<int, int> new_dp = dp;
            for (auto& [xor_val, count] : dp) {
                int new_xor = xor_val ^ num;
                new_dp[new_xor] = max(new_dp[new_xor], count + 1);
            }
            dp = new_dp;
        }
        if (dp.find(target) == dp.end())
            return -1;

        int maxSubset = dp[target];
        return n - maxSubset;
    }
};
    
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 3;
    int result = sol.minRemovals(nums, target);
    cout << "Minimum removals to achieve target XOR " << target << ": " << result << endl;
    return 0;
}