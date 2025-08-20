#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool containsDuplicate(vector<int>& nums) 
        {
            unordered_map<int,int> mp;

            for(auto& num : nums)
            {
                if(++mp[num] > 1)
                {
                    return true;
                }
            }
            return false;
        }
};

int main()
{

    return 0;
}