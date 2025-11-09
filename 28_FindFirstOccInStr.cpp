#include<iostream>
using namespace std;

class Solution 
{
    public:
        bool check(string& s, string& ndl,int idx)
        {
            int count = 0;
            for(int i = 0; idx < s.length() && i < ndl.length(); idx++,i++)
            {
                if(s[idx] != ndl[i]) break;
                count++;
            }
            return count == ndl.length() ? true : false;
        }

        int strStr(string haystack, string needle) 
        {
            int pos = -1;
            for(int i = 0; i < haystack.length(); i++)
            {
                if(haystack[i] == needle[0] && check(haystack,needle,i)) {
                    pos = i;
                    break;                    
                }
            }
            return pos;
        }
};

int main()
{

    return 0;
}