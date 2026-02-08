#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution 
{
    public:
        vector<vector<int>> res;

        void backtrack(vector<int>& nums, int start)
        {
            if(start == nums.size()) {
                res.push_back(nums);
                return;
            }

            unordered_set<int> seen;
            for(int i = start; i < nums.size(); i++) 
            {
                if(seen.count(nums[i])) continue;
                seen.insert(nums[i]);

                swap(nums[i], nums[start]);
                backtrack(nums, start + 1);
                swap(nums[i], nums[start]);
            }
        }

        vector<vector<int>> permuteUnique(vector<int>& nums) 
        {
            sort(nums.begin(), nums.end());
            backtrack(nums, 0);
            return res;
        }
};
 
int main()
{
    return 0;
}