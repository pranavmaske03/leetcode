#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int thirdMax(vector<int>& nums) 
        {
            sort(nums.begin(), nums.end());  
            int count = 1;  
            int thirdMax = nums[nums.size() - 1];  

            for (int i = nums.size() - 2; i >= 0; i--) {
                if (nums[i] != thirdMax) {
                    thirdMax = nums[i];
                    count++;
                }
                if (count == 3) return thirdMax;
            }           
            return nums[nums.size() - 1];
        }
};


int main()
{

    return 0;
}