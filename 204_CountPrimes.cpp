#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int countPrimes(int n) 
        {
            int count = 0;
            vector<bool> prime(n,true);

            for (int i = 2; i * i < n; i++) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
            for (int i = 2; i < n; i++) {
                if (prime[i] == true)
                    count++;
            }
            return count;
        }
};

int main() 
{
    int n = 10;
    Solution obj;
    cout<<obj.countPrimes(n);
    return 0;
}