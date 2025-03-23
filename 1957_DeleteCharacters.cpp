#include<iostream>
using namespace std;

class Solution 
{
    public:
        string makeFancyString(string s) 
        {
            char ch = '\0'    ;
            int limit = 1;
            string result = "";

            result += s[0];
            for (int i = 1; i < s.size(); i++)
            {
                if (s[i] == s[i-1]) {
                    limit++;
                    ch = s[i];
                }
                if(s[i] != ch) {
                    limit = 1;
                }
                if(limit < 3) {
                    result += s[i];
                }
            }
            return result;
        }
};

int main()
{
    string s = "aab";
    Solution obj;
    cout<<obj.makeFancyString(s)<<"\n";

    return 0;
}