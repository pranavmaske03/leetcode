#include<iostream>
using namespace std;

class Solution 
{
    public:
        int maxAscendingSum(vector<int>& nums) 
        {
            int sum = nums[0];
            int maxSum = 0;
            for(int i = 1; i < nums.size(); i++)     
            {
                if(nums[i] > nums[i-1]) {
                    sum += nums[i];
                    continue;
                }
                if(maxSum < sum) {
                    maxSum = sum;
                }
                sum = nums[i];
            }
            return maxSum > sum ? maxSum : sum;
        }
};

int main()
{

    return 0;
}