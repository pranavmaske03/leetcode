class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        vector<int> freq(26, 0);
        char res;

        for(int i = 0; i <= n; i++) {
            if(i < n) {
                freq[s[i] - 'a']--;
            }
            freq[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 1) {
                return i + 'a';
            }
        }
        return res;
    }
};