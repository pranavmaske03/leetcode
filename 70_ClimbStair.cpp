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
};

int main()
{
    int n = 6;

    Solution obj;
    cout<<obj.climbStairs(n)<<"\n";

    return 0;
}