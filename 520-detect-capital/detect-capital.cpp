class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int capitalCount = 0;

        for(int i = 0; i < n; i++) {
            if(isupper(word[i])) {
                capitalCount++;
            }
        }
        if(capitalCount == n || capitalCount == 0) return true;
        if(capitalCount == 1 && isupper(word[0])) return true;

        return false;
    }
};