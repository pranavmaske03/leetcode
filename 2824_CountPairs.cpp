#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int count = 0;

        while(left < right) {
            if(nums[left] + nums[right] < target) {
                count += right - left;
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;
    int result = sol.countPairs(nums, target);
    cout << "Number of pairs: " << result << endl;
    return 0;
}