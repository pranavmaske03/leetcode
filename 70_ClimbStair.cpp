#include<iostream>
using namespace std;

class Solution 
{
    public:
        int climbStairs(int n) 
        {
            if(n <= 1) return n;
    
            int prev1 = 1, prev2 = 0;
            int curr;

            for (int i = 1; i <= n; i++) 
            {
                curr = prev1 + prev2;
                prev2 = prev1;
                prev1 = curr;
            }
            return curr;
        }
        // DP - Memoization
        int ways(int n, vector<int>& memo)
        {
            if(n <= 2) return n;
            if(memo[n] != -1) return memo[n];

            memo[n] = ways(n - 1,memo) + ways(n - 2,memo);
            return memo[n];
        }

        int climbStairs(int n) 
        {
            vector<int> memo(n+1,-1);
            return ways(n,memo);
        }

        // DP - Tabulation
        int climbStairs(int n) 
        {
            if(n <= 2) return n;
            vector<int> tb(n+1,-1);
            tb[1] = 1,tb[2] = 2;
            

            for(int i = 3; i <= n; i++)
            {
                tb[i] = tb[i - 1] + tb[i - 2];
            }
            return tb[n];
        }
};

int main()
{
    int n = 6;

    Solution obj;
    cout<<obj.climbStairs(n)<<"\n";

    return 0;
}