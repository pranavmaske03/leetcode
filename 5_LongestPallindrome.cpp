#include<iostream>
#include<vector>

using namespace std;
 
class Solution 
{
    public:
        string ans = "";
        void expand(string &s , int left ,int right)
        {
            while(left >= 0 &&  right < s.size())
            {
                if(s[left] != s[right])
                    break;
                left--,right++;
            }
            if(ans.size() < right - left ) {
                ans = s.substr(left + 1 , right - left - 1);
            }
        }
        string longestPalindrome(string s) {
            for(int i = 0 ; i < s.size() ; i++)
            {
                expand(s , i , i);
                expand(s , i , i+1);
            }
            return ans;
        }
    //Manacher's Algorithm
        string longestPalindrome(string s) {
        string t = "#";
        for(char c : s){
            t += c;
            t += "#";
        }

        int n = t.size();
        vector<int> p(n,0);
        int center = 0, right = 0;
        int maxLen = 0, maxCenter = 0;

        for(int i=0;i<n;i++){
            int mirror = 2*center - i;

            if(i < right)
                p[i] = min(right - i, p[mirror]);
            while(i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1])
                p[i]++;

            if(i + p[i] > right){
                center = i;
                right = i + p[i];
            }
            if(p[i] > maxLen){
                maxLen = p[i];
                maxCenter = i;
            }
        }
        int start = (maxCenter - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};

int main()
{
    string s = "bb";
    Solution obj;
    cout<<obj.longestPalindrome(s)<<"\n";
    return 0;
}