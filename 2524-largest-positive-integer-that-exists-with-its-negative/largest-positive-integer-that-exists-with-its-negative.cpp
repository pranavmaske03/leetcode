class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int maxInt = -1;
        unordered_set<int> st(nums.begin(), nums.end());

        for(int& num : nums) {
            if(num > 0 && st.find(-num) != st.end()) {
                maxInt = max(maxInt, num);
            }
        }
        return maxInt;
    }
};