#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool Check(vector<int>& a, vector<int>& b)
        {
            for(int i = 0; i < 26; i++)
            {
                if(a[i] > b[i]) return false;
            }
            return true;
        }

        string shortestCompletingWord(string licensePlate, vector<string>& words) 
        {
            vector<int> freq(26,0);
            string res = "";
            int len = INT_MAX;

            for(char c : licensePlate) {
                if(isalpha(c)) {
                    freq[tolower(c) - 'a']++;
                }
            }
            for(auto& word : words) 
            {
                vector<int> charFreq(26,0);
                for(char ch : word) {
                    charFreq[ch - 'a']++;
                }
                if(Check(freq,charFreq)) {
                    if(word.length() < len) {
                        len = word.length();
                        res = word;
                    }
                }
            }
            return res;
        }
};

int main()
{
    return 0;
}