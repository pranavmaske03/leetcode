#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int missingNumber(vector<int>& nums) 
        {
            int n = nums.size();
            int sum = (n * (n + 1)) / 2;
            int arr_sum = 0;

            for(auto &val : nums)
            {
                arr_sum += val;
            }
            return abs(sum - arr_sum);
        }
};

int main()
{
    
    return 0;
}