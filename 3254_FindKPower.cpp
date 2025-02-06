#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> result;

        int start = 0,end = k;

        while(end <= n)
        {
            int power = nums[start];
            int max = 0;
            for(int i = start;i < end-1;i++)
            {
                if(nums[i+1]-nums[i] != 1)
                {
                    power = -1;
                    break;
                }
            }

            if(power == -1)
            {
                result.push_back(power);
            }
            else
            {
                result.push_back(nums[end-1]);
            }

            start++;
            end = start + k;
        }

        return result;
    }
};

int main()
{
    return 0;
}