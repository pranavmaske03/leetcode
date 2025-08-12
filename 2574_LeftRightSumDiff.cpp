#include<iostream>
#include<vector>
using namespace std;

class Solution  
{
    public:
        vector<int> leftRightDifference(vector<int>& nums) 
        {
            int total_sum = 0;
            int left_sum = 0;

            for(auto &num : nums) {
                total_sum += num;
            }
            for(int i = 0; i < nums.size(); i++) {
                int curr_val = nums[i];
                nums[i] = abs((total_sum - left_sum) - nums[i]);
                total_sum -= curr_val;
                left_sum += curr_val;
            }
            for(auto &num : nums) {
                cout<<num<<endl;
            }
            return nums;
        }
};

int main()
{
    vector<int> nums {10,4,8,3};
    Solution obj;
    obj.leftRightDifference(nums);

    return 0;
}