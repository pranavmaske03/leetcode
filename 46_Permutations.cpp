#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        void backtrack(vector<int>& nums, int start, vector<vector<int>>& res)
        {
            if(start == nums.size()) {
                res.push_back(nums);
                return;
            }

            for(int i = start; i < nums.size(); i++) {
                swap(nums[start],nums[i]);
                backtrack(nums, start+1, res);
                swap(nums[start],nums[i]);
            }
        }
        vector<vector<int>> permute(vector<int>& nums) 
        {
            vector<vector<int>> res;
            backtrack(nums, 0, res);
            return res;
        }
};

// using visited array
class Solution 
{
    public:
        vector<vector<int>> res;
        vector<bool> visited;

        void backtrack(vector<int>& nums, vector<int>& curr)
        {
            if(curr.size() == nums.size()) {
                res.push_back(curr);
                return;
            }

            for(int i = 0; i < nums.size(); i++) {
                if(visited[i]) continue;

                curr.push_back(nums[i]);
                visited[i] = true;

                backtrack(nums,curr);

                curr.pop_back();
                visited[i] = false;
            }
        }

        vector<vector<int>> permute(vector<int>& nums) 
        {
            vector<int> curr;
            visited.resize(nums.size(), false);
            backtrack(nums,curr);
            return res;
        }
};

int main()
{
    return 0;
}