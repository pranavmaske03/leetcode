#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        int removeDuplicates(vector<int>& nums) {
            int element = nums[0],k = 1;

            for(int i = 1; i < nums.size(); i++) {
                if(element != nums[i]) {
                    nums[k++] = nums[i];
                    element = nums[i];
                }
            }
            return k;
        }
};

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution obj;
    obj.removeDuplicates(nums);
    return 0;
}