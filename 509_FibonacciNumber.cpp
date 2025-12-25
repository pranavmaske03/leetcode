#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> memo;
        Solution() : memo(31, -1) {}

        int fib(int n) 
        {
            if(memo[n] != -1) return memo[n];
            if(n <= 1) return n;
            return memo[n] = fib(n - 1) + fib(n - 2);
        }
};

int main()
{
    return 0;
}