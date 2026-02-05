#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        void backtrack(vector<vector<int>>& res, vector<int>& curr, int start, int n, int k)
        {
            if(curr.size() == k) {
                res.push_back(curr);
                return;
            }

            for(int i = start; i <= n; i++) {
                curr.push_back(i);
                backtrack(res,curr, i + 1, n, k);
                curr.pop_back();
            }
        }

        vector<vector<int>> combine(int n, int k) 
        {
            vector<int> curr;
            vector<vector<int>>res;
            backtrack(res, curr, 1, n, k);
            return res;
        }
};

int main()
{
    return 0;
}