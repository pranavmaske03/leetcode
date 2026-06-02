#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower_pos(26, -1);
        vector<int> upper_pos(26, -1);

        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(isupper(ch) && upper_pos[ch - 'A'] == -1) upper_pos[ch - 'A'] = i;
            if(islower(ch)) lower_pos[ch - 'a'] = i;
        }

        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(lower_pos[i] != -1 && upper_pos[i] != -1 && lower_pos[i] < upper_pos[i]) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;   
}