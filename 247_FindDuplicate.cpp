#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int findDuplicate(vector<int>& nums) 
        {
            int slow = nums[0],fast = nums[0];

            while(true) {
                slow = nums[slow];
                fast = nums[nums[fast]];

                if(slow == fast) break;
            }

            int slow2 = nums[0];
            while(slow != slow2) {
                slow = nums[slow];
                slow2 = nums[slow2];
            }
            return slow;
        }
};

int main()
{
    vector<int> nums{2,5,9,6,9,3,8,9,7,1};
    Solution obj;

    cout<<obj.findDuplicate(nums);

    return 0;
}