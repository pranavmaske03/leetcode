#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:

        //  Using Memoization technique
        int helper(string& a,string& b,int i, int j, vector<vector<int>>& dp)
        {
            if(i < 0 || j < 0) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            if(a[i] == b[j]) {
                return dp[i][j] = 1 + helper(a,b,i-1,j-1,dp);
            }
            return dp[i][j] = max(helper(a,b,i-1,j,dp),helper(a,b,i,j-1,dp));
        }

        int longestCommonSubsequence(string text1, string text2) 
        {
            int m = text1.length(),n = text2.length();
            vector<vector<int>> dp(m, vector<int>(n, -1));     
            return helper(text1,text2,m - 1,n - 1,dp);
        }

        // using Tubulation technique
        int longestCommonSubsequence1(string text1, string text2) 
        {
            int m = text1.length(),n = text2.length();
            vector<vector<int>> dp(m+1, vector<int>(n+1, 0));      

            for(int i = 1; i <= m; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    if(text1[i-1] == text2[j-1]) {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    } else {
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }   
            return dp[m][n];
        }
};
int main()
{

    return 0;
}