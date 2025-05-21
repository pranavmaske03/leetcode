#include<iostream>
#include<vector>    
using namespace std;

class Solution 
{
    public:
        int search(vector<int>& nums, int target) 
        {
            int left = 0,right = nums.size()-1;
            int idx = -1;

            while(left <= right) {
                int mid = (left+right) / 2;

                if(nums[mid] == target) {
                    idx = mid;
                    return idx;
                } else if(nums[mid] > target) {
                    right--;
                } else {
                    left++;
                }
            }
            return idx;
        }
};

int main()
{
    vector<int> nums {-1,0,3,5,9,12};
    int target = 9;

    Solution obj;
    cout<<obj.search(nums,target)<<endl;

    return 0;
}