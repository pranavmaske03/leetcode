#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int countPrimes(int n) {
            int primeCount = 0;
            vector<bool> check(n+1, true);

            for(int i = 2; i < n; i++) {
                if(check[i] == true) {
                    primeCount++;
                    for(long long j = (long long)i*i; j < n; j += i) {
                        check[j] = false;
                    }
                }
            }
            return primeCount;
        }
};

int main() 
{
    int n = 10;
    Solution obj;
    cout<<obj.countPrimes(n);
    return 0;
}