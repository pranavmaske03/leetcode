#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isPallindrome(string& s)
        {
            int left = 0, right = s.length()-1;
            while(left <= right) {
                if(s[left++] != s[right--]) return false;
            }
            return true;
        }

        void backtrack(string& s, int start, vector<string>& sub, vector<vector<string>>& ans)
        {
            if(start == s.length()) {
                ans.push_back(sub);
                return;
            }

            string pallindrome_str = "";
            for(int i = start; i < s.length(); i++) {
                pallindrome_str.push_back(s[i]);

                if(isPallindrome(pallindrome_str)) {
                    sub.push_back(pallindrome_str);
                    backtrack(s, i + 1, sub, ans);
                    sub.pop_back();
                }
            }
        }

        vector<vector<string>> partition(string s) 
        {
            vector<vector<string>> ans;
            vector<string> sub;
            backtrack(s, 0, sub, ans);
            return ans;
        }
};

int main()
{
    return 0;
}