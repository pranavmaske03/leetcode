#include<iostream>
using namespace std;

class Solution 
{
public:
    int myAtoi(string s) 
    {
        int i = 0;
        int n = s.length();
        long long ans = 0;
        int sign = 1;

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        while (i < n && s[i] == '0') i++;

        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (ans * sign >= INT_MAX) return INT_MAX;
            if (ans * sign <= INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(ans * sign);
    }
};


int main()
{

    return 0;
}