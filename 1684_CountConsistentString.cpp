#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countConsistentStrings(string allowed, vector<string>& words) {
            vector<bool> isAllowed(26,false);
            int consistent = 0;
            bool isConsistent = false;

            for(int i = 0; i < allowed.length(); i++) {
                isAllowed[allowed[i] - 'a'] = true;
            }

            for(string word : words) {
                isConsistent = true;
                for(char ch : word) {
                    if(!isAllowed[ch - 'a']) {
                        isConsistent = false;
                        break;
                    }
                }
                if(isConsistent) consistent++;
            }
            return consistent;
        }
};

int main()
{
    string allowed = "abc";
    vector <string> words = {"a","b","c","ab","ac","bc","abc"};
    Solution obj;
    cout<<obj.countConsistentStrings(allowed,words);

    return 0;
}