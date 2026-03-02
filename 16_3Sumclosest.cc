#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];
                if (abs(currSum - target) < abs(res - target))
                    res = currSum;
                if (res == target)
                    return res;
                if (currSum < target)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << "The sum that is closest to " << target << " is " << sol.threeSumClosest(nums, target) << endl;
    return 0;
}