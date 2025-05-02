#include<iostream>
#include<bitset>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        unsigned int iMask = 0X55555555;
        unsigned int result = 0;

        n = n & (n-1);
        result = (n & iMask);

        return n == 0 && result == n;
    }

    // Recursive approach
    bool isPowerOfFour(int n, long long power = 1) {   
        if(n == power) return true;
        if(power > n) return false;
        return isPowerOfFour(n,power * 4);
    }
};

int main()
{
    Solution obj;
    cout<< obj.isPowerOfFour(16);

    return 0;
}
