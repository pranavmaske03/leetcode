#include<iostream>
using namespace std;

class Solution 
{
    public:
        string replaceDigits(string str) 
        {
            for(int i = 1; i < str.size(); i += 2)
            {
                int code = str[i] - '0';
                str[i] = str[i-1]+ code;
            }
            return str;
        }
};  

int main()
{

    return 0;
}