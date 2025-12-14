#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool buddyStrings(string s, string goal) {
            if (s.length() != goal.length()) return false;

            if (s == goal) {
                vector<int> freq(26, 0);
                for (char c : s) {
                    if (++freq[c - 'a'] >= 2)
                        return true;
                }
                return false;
            }

            int first = -1, second = -1;

            for (int i = 0; i < s.length(); i++) {
                if (s[i] != goal[i]) {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else
                        return false; 
                }
            }

            return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
        }
};


int main()
{

    return 0;
}