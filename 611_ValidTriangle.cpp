#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int triangleNumber(vector<int>& nums) 
        {
            std::sort(nums.begin(),nums.end());
            int n = nums.size() - 1;
            int totalTriplets = 0;

            for(int i = n; i >= 2; i--) {
                int start = 0; 
                int end = i - 1;

                while(start < end) {
                    if(nums[start] + nums[end] > nums[i]) {
                        totalTriplets += end - start;
                        end--;
                    } else {
                        start++;
                    }
                }
            }
            return totalTriplets;
        }
};

int main()
{
    vector<int> nums{2,2,3,4};
    Solution obj;
    cout<<obj.triangleNumber(nums)<<endl;

    return 0;
}