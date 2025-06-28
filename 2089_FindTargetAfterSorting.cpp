#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> targetIndices(vector<int>& nums, int target) 
        {
            sort(nums.begin(),nums.end());
            vector<int> res;

            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == target) {
                    res.push_back(i);
                }
                if(nums[i] > target) break;
            }
            return res;
        }
};

int main()
{
    vector<int> nums {1,2,5,2,3};
    int target = 2;

    Solution obj;
    obj.targetIndices(nums,target);
    
    return 0;
}