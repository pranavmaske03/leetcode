class Solution {
public:
    bool check(vector<int>& a, vector<int>& b) {
        for(int i = 0; i < 26; i++) {
            if(a[i] != 0 && a[i] > b[i]) 
                return false;
        }
        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int n = licensePlate.length();
        vector<int> lic_freq(26, 0);
        string res = "";

        for(int i = 0; i < n; i++) {
            char ch = licensePlate[i];
            if(isalpha(ch)) {
                lic_freq[tolower(ch) - 'a']++;
            }
        }

        for(auto& word : words) {
            vector<int> tmp(26, 0);
            for(char& ch : word) {
                tmp[ch - 'a']++;
            }
            if(check(lic_freq, tmp)) {
                if(res.empty()) res = word;
                else if(!res.empty() && res.length() > word.length()) {
                    res = word;
                }
            }
        }
        return res;
    }
};