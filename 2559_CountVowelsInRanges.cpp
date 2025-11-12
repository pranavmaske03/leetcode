#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isVowel(char c) {
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        }

        vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
        {
            int n = words.size();
            vector<int> prefix(n + 1, 0);
    
            for(int i = 0; i < n; i++)
            {
                string& word = words[i];

                bool isGood = isVowel(word.front()) && isVowel(word.back());
                prefix[i + 1] = prefix[i] + (isGood ? 1 : 0);
            }

            vector<int> res;
            res.reserve(queries.size());
            for(auto &query : queries)
            {
                int left = query[0];
                int right = query[1];
                int count = prefix[right + 1] - prefix[left];
                res.push_back(count);
            }
            return res;
        }
};

int main()
{

    return 0;
}