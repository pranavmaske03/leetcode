#include<iostream>
#include<vector>

class Solution 
{
    public:
        int maxAdjacentDistance(vector<int>& nums) 
        {
            int diff = 0;
            for(int i = 0; i < nums.size()-1; i++) {
                if(diff <  abs(nums[i] - nums[i+1])) {
                    diff = abs(nums[i] - nums[i+1]);
                }
            }
            return (diff < abs(nums[0] - nums[nums.size()-1]) ? abs(nums[0] - nums[nums.size()-1]) : diff);	    
        }
};

int main()
{

    return 0;
}