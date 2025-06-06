#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int singleNonDuplicate(vector<int>& nums) 
        {
            int result = 0;

            for(auto& num : nums) {
                result ^= num;
            }
            return result;
        }
        
        // using binary search technique
        int singleNonDuplicate1(vector<int>& nums) 
        {
            int low = 0,high = nums.size()-1;

            while(low < high) {
                int mid = low + (high - low) / 2;

                if(mid % 2 == 1) mid--;
                
                if(nums[mid] == nums[mid + 1]) {
                    low = mid + 2;
                } else {
                    high = mid;
                }
            }
            return nums[low];
        }
};

int main()
{
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    Solution obj;
    cout<<obj.singleNonDuplicate(nums);

    return 0;
}