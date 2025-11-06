#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> getSneakyNumbers(vector<int>& nums) 
        {
            vector<int> ans;
            vector<bool> seen(nums.size(), false);

            for (int num : nums) 
            {
                if (seen[num]) {
                    ans.push_back(num);
                } else {
                    seen[num] = true;
                }
            }
            return ans;
        }
};

int main()
{

    return 0;
}