#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
    // Using Recursion (TLE)
        int solve(int i, int j, int m, int n)
        {
            if(i >= m || j >= n) {
                return 0;
            }
            if(i == m - 1 && j == n - 1) {
                return 1;
            }
            return solve(i + 1, j, m, n) + solve(i, j + 1, m, n);
        }
        int uniquePaths(int m, int n) 
        {
            return solve(0, 0, m, n);
        }

        // using DP- memoization technique (bottom-up approach)
        int solve(vector<vector<int>>& memo,int i, int j)
        {
            int m = memo.size();
            int n = memo[0].size();

            if(i >= m || j >= n) {
                return 0;
            }
            if(i == m - 1 && j == n - 1) {
                return 1;
            }
            if(memo[i][j] != -1) {
                return memo[i][j];
            }
            memo[i][j] = solve(memo,i + 1, j) + solve(memo,i, j + 1);
            return memo[i][j];
        }
        
        // using DP - Tabulation technique (to- down approach)
        int uniquePaths(int m, int n) 
        {
            vector<vector<int>> dp(m,vector<int>(n,1));

            for(int i = 1; i < m; i++)
            {
                for(int j = 1; j < n; j++)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
            return dp[m-1][n-1];
            //return solve(dp,0, 0);
        }
};

int main()
{
    return 0;
}