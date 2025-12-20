#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int Check(vector<int>& nums, int k)
        {
            int oddCount = 0,result = 0;
            int left = 0;

            for(int right = 0; right < nums.size(); right++ ) 
            {
                if(nums[right]%2 == 1) oddCount++;

                while(oddCount > k) {
                    if(nums[left]%2 == 1) oddCount--;
                    left++;
                }

                result += (right - left + 1);
            }
            return result;
        }

        int numberOfSubarrays(vector<int>& nums, int k) 
        {
            return Check(nums,k) - Check(nums,k-1);
        }
};

int main()
{
    
    return 0;
}