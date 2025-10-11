#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> sortArrayByParityII(vector<int>& nums) 
        {
            int i = 0,j = 1;
            int n = nums.size();

            while(i < n && j < n) 
            {
                if(nums[i]%2 == 1 && nums[j]%2 == 0) {
                    swap(nums[i],nums[j]);
                }
                if(nums[i]%2 == 0) i += 2;
                if(nums[j]%2 == 1) j += 2;
            }
            return nums;
        }
};

int main()
{

    return 0;
}