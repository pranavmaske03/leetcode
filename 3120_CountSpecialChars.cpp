#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        int count = 0;

        for(auto ch : word) {
            if(isupper(ch)) {
                upper[ch - 'A'] = true;
            } else {
                lower[ch - 'a'] = true;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(lower[i] && upper[i]) count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    string word = "aA";
    cout << sol.numberOfSpecialChars(word) << endl;
    return 0;
}