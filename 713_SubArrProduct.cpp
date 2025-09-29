#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) 
        {
            long long product = 1;
            int left = 0,count = 0;

            for(int right = 0; right < nums.size(); right++)
            {              
                product *= nums[right];
                while(product >= k && left <= right) {
                    product /= nums[left++];
                }
                if(product < k) {
                    count += right - left + 1;
                }
            }
            return count;
        }
};

int main()
{

    return 0;
}