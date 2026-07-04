class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int curr = 0, count = 0;

        for(int i = 0; i < n; i++) {
            if(curr != nums[i]) {
                curr = nums[i];
                count = 1;
            } else {
                count++;
            }

            if(count <= k)
                res.push_back(nums[i]);
        }
        return res;
    }
};