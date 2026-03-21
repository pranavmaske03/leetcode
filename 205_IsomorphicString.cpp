#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s_to_t(256, -1);
        vector<int> t_to_s(256, -1);

        for(int i = 0; i < s.length(); i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if(s_to_t[ch1] != -1 && s_to_t[ch1] != ch2 || t_to_s[ch2] != -1 && t_to_s[ch2] != ch1) {
                return false;
            }
            s_to_t[ch1] = ch2;
            t_to_s[ch2] = ch1;
        }
        return true;
    }
};

int main()
{

    return 0;
}