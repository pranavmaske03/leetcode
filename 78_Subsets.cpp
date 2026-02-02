#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<vector<int>> res;
        vector<int> curr;

        void backtrack(vector<int>& nums, int index) {
            res.push_back(curr);

            for (int i = index; i < nums.size(); i++) {
                curr.push_back(nums[i]);      
                backtrack(nums, i + 1);      
                curr.pop_back();           
            }
        }

        vector<vector<int>> subsets(vector<int>& nums) {
            backtrack(nums, 0);
            return res;
        }
};

int main()
{
    return 0;
}