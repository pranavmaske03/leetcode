#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        string res = "";
        int i = 0, j = 0;

        while(i < n1 && j < n2) {
            res += word1[i++];
            res += word2[j++];
        }
        res += word1.substr(i);
        res += word2.substr(j);

        return res;
    }
};

int main() {
    return 0;
}