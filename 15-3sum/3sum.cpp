class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> res;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0)
                break;
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0)
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;

                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }
};