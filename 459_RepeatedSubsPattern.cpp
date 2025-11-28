#include<iostream>
using namespace std;

class Solution 
{
    public:
        bool repeatedSubstringPattern(string s) 
        {
            int n = s.size();
            if (n == 0) return false;       
            string doubled = s + s;
            string trimmed = doubled.substr(1, 2*n - 2);
            return trimmed.find(s) != string::npos;
        }
};

int main()
{

    return  0;
}