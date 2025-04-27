#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) 
        {
            int idx = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] != 0) {
                    swap(nums[i],nums[idx]);
                    idx++;
                }
            }
        }
};

int main()
{
    vector<int> nums = {0,1,0,3,12};
    Solution obj;
    obj.moveZeroes(nums);

    return 0;
}