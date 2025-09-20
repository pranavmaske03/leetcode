#include<iostream>
using namespace std;

class Solution 
{
    public:
        string reverseStr(string s, int k) 
        {
            int i = 0;
            while(i < s.length())
            {
                int end = min((int)s.length(), i + k);
                reverse(s.begin() + i, s.begin() + end);
                i += (2 * k);
            }    
            return s;
        }
};

int main()
{

    return 0;
}