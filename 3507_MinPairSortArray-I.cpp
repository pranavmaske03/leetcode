#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isNonDecreasing(vector<int>& nums)
        {
            for(int i = 0; i + 1 < nums.size(); ++i) {
                if(nums[i] > nums[i + 1]) return false;
            }
            return true;
        }

        int minimumPairRemoval(vector<int>& nums) 
        {
            int ops = 0;

            while(!isNonDecreasing(nums)) 
            {
                int minSum = INT_MAX;
                int minIdx = 0;

                for(int i = 0; i < nums.size() - 1; i++)
                {
                    int sum = nums[i] + nums[i + 1];
                    if(sum < minSum) {
                        minSum = sum;
                        minIdx = i;
                    }
                }
                nums[minIdx] = minSum;
                nums.erase(nums.begin() + minIdx + 1);
                ops++;
            }
            return ops;
        }
};

int main()
{
    return 0;
}