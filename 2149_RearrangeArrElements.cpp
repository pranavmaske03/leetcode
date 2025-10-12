#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> rearrangeArray(vector<int>& nums)
        {
            vector<int> res(nums.size(),0);
            int positiveIdx = 0,negativeIdx = 1;

            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] > 0) {
                    res[positiveIdx] = nums[i];
                    positiveIdx += 2;
                } else {
                    res[negativeIdx] = nums[i];
                    negativeIdx += 2;
                }
            }
            return res;
        }
};

int main()
{

    return 0;
}