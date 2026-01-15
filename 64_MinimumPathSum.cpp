#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    // Using DP - Memoization 
    private:
        vector<vector<int>> dp;
        int m;
        int n;

    public:
        int Solve(vector<vector<int>>& grid, int i, int j)
        {
            if(i == m - 1 && j == n - 1) return grid[i][j];

            if(dp[i][j] != -1) {
                return dp[i][j];
            }

            int right = INT_MAX;
            int down  = INT_MAX;

            if(j + 1 < n) right = Solve(grid, i, j + 1);
            if(i + 1 < m) down = Solve(grid, i + 1, j);

            return dp[i][j] = grid[i][j] + min(right,down);
        }

        int minPathSum(vector<vector<int>>& grid) 
        {
            m = grid.size();
            n = grid[0].size();
            dp.assign(m, vector<int>(n, -1));

            int ret = Solve(grid,0,0);
            return ret;
        }
    
    // Using DP - Tabulation
        int minPathSum(vector<vector<int>>& grid) 
        {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n));

            for(int i = m - 1; i >= 0; i--)
            {
                for(int j = n - 1; j >= 0; j--)
                {
                    if(i == m - 1 && j == n - 1) {
                        dp[i][j] = grid[i][j];
                    } else if(i == m - 1) {
                        dp[i][j] = grid[i][j] + dp[i][j + 1];
                    } else if(j == n - 1) {
                        dp[i][j] = grid[i][j] + dp[i + 1][j];
                    } else {
                        dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
                    }
                }
            }
            return dp[0][0];
        }
};

int main()
{
    return 0;
}