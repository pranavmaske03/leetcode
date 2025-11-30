#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
        {
            vector<int> diff(nums.size()+1,0);

            for(auto& query : queries) {
                int start = query[0];
                int end = query[1];

                diff[start] += 1;
                diff[end+1] += -1;
            }

            long long currSum = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                currSum += diff[i];
                if(nums[i] > currSum) return false;
            }
            return true;
        }
};

int main()
{

    return 0;
}