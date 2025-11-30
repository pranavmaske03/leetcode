#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        void check(vector<int>& a, vector<int>& b)
        {
            for(int i = 0; i < 26; i++) {
                a[i] = min(a[i],b[i]);
            }
        }

        vector<string> commonChars(vector<string>& words) 
        {
            vector<int> freq(26,0);
            vector<string> ans;

            string word = words[0];
            for(char& ch : word) {
                freq[ch - 'a']++;
            }

            for(int i = 1; i < words.size(); i++) {
                vector<int> tmp(26, 0);
                for(char ch : words[i]) {
                    tmp[ch - 'a']++;
                }
                check(freq, tmp);
            }

            for(int i = 0; i < 26; i++) {
                while(freq[i] > 0) {
                    ans.push_back(string(1, i + 'a'));
                    freq[i]--;
                }
            }
            return ans;
        }
};

int main()
{

    return 0;
}