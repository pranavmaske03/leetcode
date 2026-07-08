class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int m = -1,n = -1;
        for(int i = 0,j = nums.size()-1; i < nums.size() && j >= 0; i++,j--) 
        {
            if(nums[i] == target && m == -1) {
                m = i;
            } 
            if(nums[j] == target && n == -1) {
                n = j;
            }
        }
        return {m,n};
    }
};