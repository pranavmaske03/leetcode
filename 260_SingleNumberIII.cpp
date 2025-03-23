#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) 
        {
            int n = nums.size();
            long long xorr = 0; //SINCE XOR CAN BE INT_MIN AND XOR-1 CAN OVERFLOW

            for(int i = 0; i < n; i++) 
            {
                xorr = xorr^nums[i];
            }

            int rightmostset = (xorr^(xorr-1)) & xorr;
            int b1 = 0,b2 = 0;

            for(int i = 0; i < n; i++) {            
                if(nums[i] & rightmostset) {
                    b1 ^= nums[i];
                } else {
                    b2 ^= nums[i];
                }
            }
            return {b1,b2};
        }
};


int main()
{
    vector<int>  nums = {1,2,1,3,2,5};
    Solution obj;
    obj.singleNumber(nums);
}