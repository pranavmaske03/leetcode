class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        int leftSum = 0;
        for(int i = 0; i < n; i++) {
            res[i] = leftSum;
            leftSum += nums[i];
        }
        int rightSum = 0;
        for(int i = n - 1; i >= 0; i--) {
            res[i] = abs(res[i] - rightSum);
            rightSum += nums[i];
        }
        return res;
    }
};