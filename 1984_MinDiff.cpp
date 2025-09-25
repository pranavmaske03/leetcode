#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;

        int minNum = INT_MAX;
        int i = 0;

        sort(nums.begin(),nums.end());
        while(i <= nums.size() - k) { 
            int diff = nums[i+k-1] - nums[i];
            i++;
            minNum = min(minNum , diff);
        }
        return minNum;
    }
};

int main()
{

    return 0;
}