class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_val = INT_MAX;

        for(int& num : nums) {
            min_val = min(min_val, num);
        }
        return min_val;
    }
};