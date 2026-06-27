class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        string str = s + s;
        string trimmed = str.substr(1, 2*n - 2);
        return trimmed.find(s) != string::npos;
    }
};