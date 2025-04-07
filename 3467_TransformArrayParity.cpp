#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> transformArray(vector<int>& nums) 
        {
            vector<int> result(nums.size(),0);
            int odd = nums.size() - 1;

            for(int i = 0; i < nums.size(); i++) 
            {
                if(nums[i]%2) {
                    result[odd--] = 1;
                }
            }
            return result;
        }
};

int main()
{

    return 0;
}