#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        void backtrack(vector<int>& vec, vector<int>& sub, vector<vector<int>>& res, int j, int sum)
        {
            if(sum == 0) {
                res.push_back(sub);
                return;
            }

            for(int i = j; i < vec.size(); i++) {
                if(i > j && vec[i] == vec[i - 1]) continue;
                if(vec[i] > sum) break;

                sub.push_back(vec[i]);
                backtrack(vec, sub, res, i + 1, sum - vec[i]);
                sub.pop_back();
            }
        }

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
        {
            vector<vector<int>> res;
            vector<int> subset;
            sort(candidates.begin(), candidates.end());
            backtrack(candidates, subset, res , 0, target);
            return res;
        }
};
                                                                                                                      
int main()
{
    return 0;
}