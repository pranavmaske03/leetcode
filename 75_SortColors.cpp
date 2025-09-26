#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        void sortColors(vector<int>& nums) 
        {
            int right = nums.size()-1,left = 0;

            int i = 0;
            while(i <= right)
            {
                if(nums[i] == 0) {
                    swap(nums[i],nums[left++]);
                }
                if(nums[i] == 2) {
                    swap(nums[i],nums[right--]);
                    continue;
                }
                i++;
            }
        }
};

int main()
{

    return 0;
}