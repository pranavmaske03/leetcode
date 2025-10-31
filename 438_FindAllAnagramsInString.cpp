#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isAnagram(vector<int>& a, vector<int>& b) {
            for(int i = 0; i < 26; i++) {
                if(a[i] != b[i]) return false;
            }
            return true;
        }

        vector<int> findAnagrams(string s, string p) 
        {
            int n = s.size(),m = p.size();
            vector<int> ans;
            if(n < m) return ans;

            vector<int> p_freq(26,0),window_freq(26,0);

            for(int i = 0; i < m; i++) {
                p_freq[p[i] - 'a']++;
            }

            for(int i = 0; i < n; i++) {
                window_freq[s[i] - 'a']++;

                if(i >= m) {
                    window_freq[s[i - m] - 'a']--;
                }
                if(isAnagram(p_freq,window_freq)) {
                    ans.push_back(i - m + 1);
                }
            }
            return ans;
        }
}; 

int main()
{

    return 0;
}