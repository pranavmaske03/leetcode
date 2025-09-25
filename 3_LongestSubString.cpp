#include<iostream>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        int lengthOfLongestSubstring(string s) 
        {
            int left = 0,maxLength = 0;
            unordered_map<char,int> mp;

            for(int right = 0; right < s.length(); right++)
            {
                if(mp[s[right]] > left) {
                    left = mp[s[right]];
                }
                mp[s[right]] = right + 1;
                maxLength = max(maxLength,right - left + 1);
            }
            return maxLength;
        }
};

int main()
{

    return 0;
}