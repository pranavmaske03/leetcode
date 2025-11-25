#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int numIdenticalPairs(vector<int>& nums) 
        {
            vector<int> count(101,0);
            int good = 0;

            for(int i = 0; i < nums.size(); i++)
            {
                if(count[nums[i]] > 0) {
                    good += count[nums[i]];
                }
                count[nums[i]]++;
            }
            return good;
        }
};

int main()
{

    return 0;
}