#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int passwordStrength(string password) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        vector<bool> digit(10, false);
        vector<bool> special(4, false);
        int strength = 0;
        for(int i = 0; i < password.length(); i++) {
            char ch = password[i];

            if(islower(ch) ) {
                int idx = ch - 'a';
                if(!lower[idx]) {
                    strength += 1;
                     lower[idx] = true;
                }
            } else if(isupper(ch)) {
                int idx = ch - 'A';
                if(!upper[idx]) {
                    strength += 2;
                    upper[idx] = true;
                }
            } else if(isdigit(ch)) {
                int idx = ch - '0';
                if(!digit[idx]) {
                    strength += 3;
                    digit[idx] = true;
                }
            } else {
                string sp = "!@#$";
                int idx = sp.find(ch);
                if(idx != string::npos && !special[idx]) {
                    strength += 5;
                    special[idx] = true;
                }
            }
        }
        return strength;
    }
};
    
int main() {
    Solution sol;
    cout << sol.passwordStrength("Password123!") << endl;
    return 0;
}