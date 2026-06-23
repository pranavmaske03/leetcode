class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int last_idx = n - 1;
        int left = 0, right = n - 1;

        while(left <= right) {
            int left_sqr = nums[left] * nums[left];
            int right_sqr = nums[right] * nums[right];

            if(left_sqr > right_sqr) {
                res[last_idx--] = left_sqr;
                left++;
            } else {
                res[last_idx--] = right_sqr;
                right--;
            }
        }
        return res;
    }
};