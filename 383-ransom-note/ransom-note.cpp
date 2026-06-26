class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);

        for(auto& ch : magazine) {
            freq[ch - 'a']++;
        }

        for(auto& ch : ransomNote) {
            if(freq[ch - 'a']-- <= 0) {
                return false;
            }
        }
        return true;
    }
};