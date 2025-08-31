#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int pivotIndex(vector<int>& nums) 
        {
            int total_sum = 0,left_sum = 0;
            int pivot_index = -1;

            for(auto& num : nums) {
                total_sum += num;
            }

            for(int i = 0; i < nums.size(); i++)
            {
                if(left_sum == total_sum - left_sum - nums[i]) {
                    pivot_index = i;
                    break;
                }
                left_sum += nums[i];
            }
            return pivot_index;
        }
};

int main()
{
    return 0;
}