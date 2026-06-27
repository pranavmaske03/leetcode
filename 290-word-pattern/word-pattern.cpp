class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p_to_s;
        unordered_map<string, char> s_to_p;

        stringstream ss(s);
        string word;

        for(int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            if(!(ss >> word)) return false;

            if(p_to_s.count(ch) && p_to_s[ch] != word) return false;
            if(s_to_p.count(word) && s_to_p[word] != ch) return false;
            
            p_to_s[ch] = word;
            s_to_p[word] = ch;
        }
        if(ss >> word) return false;
        return true;
    }
};