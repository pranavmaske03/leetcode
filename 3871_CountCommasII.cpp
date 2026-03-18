#include<iostream>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;

        if(n >= 1000) {
            res += n - 999;
        }
        if(n >= 1000000) {
            res += n - 999999;
        }
        if(n >= 1000000000) {
            res += n - 999999999;
        }
        if(n >= 1000000000000) {
            res += n - 999999999999;
        }
        if(n >= 1000000000000000) {
            res += n - 999999999999999;
        }
        
        return res;
    }
};

int main()
{
    return 0;
}