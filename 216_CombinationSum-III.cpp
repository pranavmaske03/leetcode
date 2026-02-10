#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<vector<int>> res;
        vector<int> sub;

        void backtrack(int& k, int target, int start)
        {
            if(sub.size() == k && target == 0) {
                res.push_back(sub);
                return;
            }

            for(int i = start; i <= 9; i++) {
                if(i > target) break;                
                sub.push_back(i);
                backtrack(k, target - i, i + 1);
                sub.pop_back();
            }
        }

        vector<vector<int>> combinationSum3(int k, int n) 
        {
            backtrack(k, n, 1);
            return res;
        }
};

int main()
{
    return 0;
}