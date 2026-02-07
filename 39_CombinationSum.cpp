#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<vector<int>> res;

        void backtrack(vector<int>& candidates, vector<int>& curr, int start, int target)
        {
            if(target < 0) return;

            if(target == 0) {
                res.push_back(curr);
                return;
            }
            for(int i = start; i < candidates.size(); i++) {
                curr.push_back(candidates[i]);
                backtrack(candidates, curr, i , target - candidates[i]);
                curr.pop_back();
            }
        }

        vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
        {
            vector<int> curr;
            backtrack(candidates, curr, 0, target);
            return res;
        }
};

int main()
{
    return 0;
}