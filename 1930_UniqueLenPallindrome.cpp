#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int countPalindromicSubsequence(string s) 
        {
            vector<int> firstIdx(26,-1),lastIdx(26,-1);
            vector<pair<int,int>> idx(26,{-1,-1});

            for(int i = 0; i < s.length(); i++)
            {
                int c = s[i] - 'a';
                if(idx[c].first == -1) idx[c].first = i;
                idx[c].second = i;
            }

            int ans = 0;
            for(int i = 0; i < 26; i++)
            {
                int L = idx[i].first;
                int R = idx[i].second;

                if(L == -1 || R - L < 2) continue;

                unordered_set<char> st;

                for(int i = L + 1; i < R; i++) {
                    st.insert(s[i]);
                }
                ans += st.size();
            }
            return ans;
        }
};

int main()
{

    return 0;
}