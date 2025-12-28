#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int tib(int n, vector<int>& memo)
        {
            if(memo[n] != -1) return memo[n];
            memo[n] = tib(n - 3,memo) + tib(n - 2,memo) + tib(n - 1,memo);
            return memo[n];
        }

        int tribonacci(int n) 
        {
            if(n == 0) return 0;
            if(n == 1 || n == 2) return 1;

            vector<int> memo(n+1, -1);
            memo[0] = 0,memo[1] = 1,memo[2] = 1;
            return tib(n,memo);
        }
};

int main()
{

    return 0;
}