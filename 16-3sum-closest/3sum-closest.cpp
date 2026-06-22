class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum == target) 
                    return sum;
                if(abs(sum - target) < abs(res - target))
                    res = sum;

                if(sum > target) k--;
                else j++;
            }
        }
        return res;
    }
};
