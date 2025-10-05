#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution 
{
    public:
        void nextPermutation(vector<int>& nums) 
        {
            int n = nums.size()-1;
            int pivot = -1;

            for(int i = n-2; i >= 0; i--) {
                if(nums[i] < nums[i+1]) {
                    pivot = i;
                    break;
                }
            }
            if(pivot != -1) {
                for(int i = n-1; i >= 0; i--) {
                    if(nums[i] > nums[pivot]) {
                        swap(nums[i],nums[pivot]);
                        reverse(nums.begin() + pivot + 1, nums.end());
                        break;
                    }
                } 
            } else {
                reverse(nums.begin(), nums.end()); 
            }
        }
};

int main()
{

    return 0;
}