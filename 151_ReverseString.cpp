#include<iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
        string reverseWords(string s) 
        {
            int n = s.length();
            string ans = "";
            int i = 0;
            while (i < n) 
            {
                string temp;
                while (i < n && s[i] == ' ') {
                    i++;
                }
                
                while (i < n && s[i] != ' ') {
                    temp += s[i];
                    i++;
                }
               
                if (!temp.empty()) {
                    if (ans.empty()) {
                        ans = temp;
                    } else {
                        ans = temp + " " + ans;
                    }
                }
            }
            return ans;
    }
};

int main()
{
    string str = "   the   sky   is   blue  ";
    Solution obj;
    obj.reverseWords(str);

    
    return 0;
}