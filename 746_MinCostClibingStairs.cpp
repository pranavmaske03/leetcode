#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:

        // DP - Memoization technique
        int minCost(vector<int>& cost, int idx, vector<int>& memo)
        {
            if(idx >= cost.size()) return 0;
            if(memo[idx] != -1) return memo[idx];

            return memo[idx] = cost[idx] + min (
                minCost(cost, idx + 1, memo),
                minCost(cost, idx + 2, memo)
            );
        }

        int minCostClimbingStairs(vector<int>& cost) 
        {
            vector<int> memo(cost.size(), -1);
            return min (
                minCost(cost, 0, memo),
                minCost(cost, 1, memo)
            );
        }

        // DP - Tabulation technique
        int minCostClimbingStairs(vector<int>& cost) 
        {
            int n = cost.size();
            vector<int> dp(n,0);

            dp[0] = cost[0];
            dp[1] = cost[1];

            for(int i = 2; i < n; i++)
            {
                dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
            }
            return min(dp[n-1],dp[n-2]);
        }
};

int main()
{

    return 0;
}