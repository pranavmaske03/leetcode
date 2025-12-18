#include<iostream>
using namespace std;

class Solution 
{
    public:
        string reverseWords(string s) 
        {
            int left = 0;

            for (int right = 0; right < s.length(); right++)
            {
                if (s[right] == ' ')
                {
                    reverse(s.begin() + left, s.begin() + right);
                    left = right + 1;
                }
                else if (right == s.length() - 1)
                {
                    reverse(s.begin() + left, s.begin() + right + 1);
                }
            }
            return s;
        }
};


int main()
{

    return 0;
}