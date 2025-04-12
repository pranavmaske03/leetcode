#include<iostream>
using namespace std;

class Solution 
{
    public:
        string convertToBase7(int num) 
        {
            if (num == 0) {
                return "0";
            }

            string s;
            int minus = 0;

            if (num < 0) {
                minus = -1;
                num *= -1;
            }

            while (num) {
                s += (num%7) + '0';
                num /= 7;
            }
        
            reverse(s.begin(),s.end());

            if (minus == -1){
                s = "-" + s;
            }
            return s;
        }
};

int main()
{

    return 0;
}