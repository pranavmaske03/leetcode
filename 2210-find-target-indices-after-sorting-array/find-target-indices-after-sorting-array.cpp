class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int less = 0, cnt = 0;

        for(int& num : nums) {
            if(num < target) {
                less++;
            } else if(num == target) {
                cnt++;
            }
        }

        vector<int> res;
        for(int i = 0; i < cnt; i++) {
            res.push_back(i + less);
        }
        return res;
    }
};