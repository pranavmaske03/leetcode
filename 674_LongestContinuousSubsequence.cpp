#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int findLengthOfLCIS(vector<int>& nums) 
        {
            int count = 1,max_len = 1;

            for(int i = 1; i < nums.size(); i++) 
            {
                if(nums[i] > nums[i-1]) {
                    count++;
                    max_len = max(max_len,count);
                } else {
                    count = 1;
                }
            }
            return max_len;
        }
};

int main()
{

    return 0;
}