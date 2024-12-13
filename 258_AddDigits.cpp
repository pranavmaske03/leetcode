#include<iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) 
    {
        int sum = 0,digit = 0;

        while(num > 9)    
        {
            sum = 0;
            while(num != 0)
            {
                digit = num % 10;
                sum += digit;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

int main()
{
    int n = 0;

    Solution obj;
    cout<<obj.addDigits(n)<<endl;

    return 0;
}