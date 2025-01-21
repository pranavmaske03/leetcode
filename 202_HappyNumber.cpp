#include<iostream>
using namespace std;

class Solution 
{
    public:
        bool isHappy(int n) 
        {
            int sum = 0,digit = 0;
            while(true)    {
                sum = 0;
                while(n != 0) {
                    digit = n % 10;
                    sum += (digit * digit);
                    n /= 10;
                }
                n = sum;\
                if(sum == 1) {
                    return true;
                }
                if(sum == 4) return false;
            }
        }
};

int main()
{


    return 0;
}