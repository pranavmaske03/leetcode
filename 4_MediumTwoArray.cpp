#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
        {
            double medium = 0.0;

            nums1.insert(nums1.end(), nums2.begin(), nums2.end());  
            sort(nums1.begin(),nums1.end());

            if(nums1.size() % 2 != 0) {
                int index = nums1.size() / 2;
                medium = double(nums1[index]);
            } else {
                int index = nums1.size() / 2;
                medium = nums1[index-1] + nums1[index];
                medium = medium / 2;    
            }
            return medium;
        }
};

int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    Solution obj;
    double ret = obj.findMedianSortedArrays(nums1,nums2);
    cout<<(ret)<<endl;
}