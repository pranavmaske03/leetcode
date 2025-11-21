#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        string reverseParentheses(string s) 
        {
            vector<int> idx;

            for(int i = 0; i < s.length(); i++)
            {
                if(s[i] == '(') idx.push_back(i);

                if(s[i] == ')') {
                    int left = idx.back();
                    idx.pop_back();
                    reverse(s.begin() + left + 1,s.begin() + i);
                }
            }

            string ans = "";
            for(int i = 0; i < s.length(); i++) 
            {
                if(s[i] != '(' && s[i] != ')') {
                    ans += s[i];
                }
            }
            return ans;
        }
};

int main()
{

    return 0;
}