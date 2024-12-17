#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isUgly(int n) 
        {
            if(n < 1) return false;
            vector<int> primes = {2,3,5};

            for(auto p : primes)
            {
                while(n % p == 0) {
                    n /= p;
                }
            }
            return n == 1;
        }
};
int main()
{
    Solution obj;

    cout<<obj.isUgly(7);
    
    return 0;
}