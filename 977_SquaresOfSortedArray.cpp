#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> sortedSquares(vector<int>& nums) 
        {
            int l = 0,r = nums.size()-1;
            vector<int> res(nums.size());

            for(int i = nums.size()-1; i >= 0; i--)
            {
                int left = nums[l] * nums[l];
                int right = nums[r] * nums[r];

                if(left > right) {
                    res[i] = left;
                    l++;
                } else {
                    res[i] = right;
                    r--;
                }
            }
            return res;
        }
};

int main()
{
    vector<int> nums{};
    Solution obj;
    vector<int> res = obj.sortedSquares(nums);
    return 0;
}