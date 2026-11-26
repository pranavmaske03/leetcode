class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int evenIdx = 0;
        int oddIdx = 1;

        while(oddIdx < n && evenIdx < n) {
            if(nums[oddIdx]%2 == 0 && nums[evenIdx]%2 == 1) {
                swap(nums[oddIdx], nums[evenIdx]);
            }
            if(nums[evenIdx]%2 == 0) 
                evenIdx += 2;
            if(nums[oddIdx]%2 == 1)
                oddIdx += 2;
        }
        return nums;
    }
};