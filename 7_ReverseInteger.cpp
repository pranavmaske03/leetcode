#include<iostream>
using namespace std;

class Solution 
{
    public:
        int reverse(int x) 
        {
            long int reverse = 0;

            while(x != 0) {
                int digit = x % 10;
                reverse = (reverse * 10) + digit;
                x /= 10;
            }

            if(reverse > INT_MAX || (reverse < INT_MIN)) {
                return 0;
            } else {
                return reverse;
            }
        }
};

int main()
{
    return 0;
