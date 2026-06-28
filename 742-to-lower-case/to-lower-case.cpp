class Solution {
public:
    string toLowerCase(string s) {
        for(auto& ch : s) {
            ch = tolower(ch);
        }
        return s;
    }
};