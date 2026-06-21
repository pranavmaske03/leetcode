class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int res = 0;

        sort(nums.begin(), nums.end());
        while(left < right) {
            int sum = nums[left] + nums[right];

            if(sum < target) {
                res += right - left;
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};