#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int getCommon(vector<int>& nums1, vector<int>& nums2) 
        {
            int minCommon = -1;
            int idx1 = 0,idx2 = 0;

            while(idx1 < nums1.size() && idx2 < nums2.size())
            {
                if(nums1[idx1] == nums2[idx2]) {
                    minCommon = nums1[idx1];
                    break;
                }

                if(nums1[idx1] < nums2[idx2]) {
                    idx1++;
                } else {
                    idx2++;
                }
            }    
            return minCommon;
        }
};

int main()
{

    return 0;
}