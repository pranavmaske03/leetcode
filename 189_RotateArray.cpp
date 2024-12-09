#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class Solution 
{
    public:
        void rotate(vector<int>& nums, int k) 
        {
            int n = nums.size();
            k = k % n; // Ensure k is within the range [0, n)

            // Reverse the entire array
            reverse(nums.begin(), nums.end());
            
            // Reverse the first k elements
            reverse(nums.begin(), nums.begin() + k);
            
            // Reverse the rest of the elements after k
            reverse(nums.begin() + k, nums.end());
        }
};
int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    Solution obj;
    obj.rotate(nums,k);

    return 0;
}