#include<iostream>
#include<vector>
using namespace std;

class Solution 
    {
    public:
        vector<int> shortestToChar(string s, char c) 
        {
            int n = s.length();
            vector<int> ans(n,0);
        
            // calculate distance left -> right 
            int last = -n;
            for(int i = 0; i < s.length(); i++) 
            {
                if(s[i] == c) last = i;
                ans[i] = i - last;
            }

            // calculate distance right -> left
            last = INT_MAX;
            for(int i = n - 1; i >= 0; i--)
            {
                if(s[i] == c) last = i;
                ans[i] = min(ans[i], last - i);
            }
            return ans;
        }
};

int main()
{

    return 0;
}