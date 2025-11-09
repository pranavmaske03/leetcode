#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        string minWindow(string s, string t) 
        {
            vector<int> mp(256,0);
            int startIdx = -1,found = 0;
            int minLen = INT_MAX;
            int left = 0;

            for(int i = 0; i < t.length(); i++) {
                mp[t[i]]++;
            }

            for(int right = 0; right < s.length(); right++)
            {
                if(mp[s[right]]-- > 0) {
                    found++;
                }

                while(found == t.size()) 
                {
                    int min = right - left + 1;
                    if(min < minLen) {
                        minLen = min;
                        startIdx = left;
                    }

                    if(++mp[s[left++]] > 0) {
                        found--;
                    }
                }
            }
            return startIdx == -1 ? "" : s.substr(startIdx,minLen);
        }
};

int main()
{

    return 0;
}