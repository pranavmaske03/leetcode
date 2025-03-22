#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> findDuplicates(vector<int>& nums) 
        {
            vector<int> result;
            int n = nums.size();

            for(int i = 0; i < n; i++) 
            {
                int val = abs(nums[i]);
                if(nums[val-1] < 0){
                    
                    result.push_back(val);
                }
                nums[val-1] *= -1;
            }
            return result;
        }
};
int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution obj;

    obj.findDuplicates(nums);

    return 0;
}