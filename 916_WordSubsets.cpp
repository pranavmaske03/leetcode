#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool compare(vector<int>& a, vector<int>& b)
        {
            for(int i = 0; i < 26; i++)
            {
                if(a[i] != 0 && b[i] < a[i]) return false;
            }
            return true;
        }

        vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
        {
            vector<int> maxFreq(26,0);
            vector<string> ans;

            for(auto& word : words2)
            {
                vector<int> b_freq(26,0);
                for(auto& ch : word)
                {
                    b_freq[ch - 'a']++;
                    maxFreq[ch - 'a'] = max(maxFreq[ch - 'a'],b_freq[ch - 'a']);
                }
            }

            for(auto& word : words1)
            {
                vector<int> a_freq(26,0);
                for(auto& ch : word)
                {
                    a_freq[ch - 'a']++;
                }
                if(compare(maxFreq,a_freq)) {
                    ans.push_back(word);
                }
            }
            return ans;
        }
};

int main()
{

    return 0;
}