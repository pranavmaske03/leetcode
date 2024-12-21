#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        bool search(vector<int>& nums, int target) 
        {        
            int low = 0,high = nums.size()-1;

            while(low <= high) {
                int mid = (low -+high) / 2;

                if(nums[mid] == target) {
                    return true;
                }
                if(nums[low] == nums[mid]) {
                    low++;
                    continue;
                }
                if(nums[low] <= nums[mid]) {
                    if((nums[low] <= target) && (target <= nums[mid])) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    if((nums[mid] <= target) && (target <= nums[high])) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            return false;
        }
};

int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 9;
    Solution obj;
    cout<<obj.search(nums,target)<<endl; 

    return 0;
}