class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2, 0);
        int left = 0, right = nums.size() - 1;

        while(left < right) {
            int sum = nums[left] + nums[right];

            if(sum == target) {
                res[0] = left + 1;
                res[1] = right + 1;
                break;
            }

            if(sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
};