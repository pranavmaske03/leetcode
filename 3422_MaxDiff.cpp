#include<iostream>
using namespace std;

class Solution 
{
    public:
        int maxDifference(string s) 
        {
            vector<int> freq(26,0);
            int max_freq = INT_MIN;
            int min_freq = INT_MAX;

            for(int i = 0; i < s.length(); i++) 
            {
                freq[s[i] - 'a']++;
            }
            for(int i = 0; i < 26; i++)
            {
                if(freq[i] < min_freq && freq[i] != 0 && freq[i]%2 == 0)
                {
                    min_freq = freq[i];
                }
                if(freq[i] > max_freq && freq[i] != 0 && freq[i]%2)
                {
                    max_freq = freq[i];
                }
            }
            cout<<max_freq<<" "<<min_freq;
            return max_freq - min_freq;
        }
};

int main()
{

    return 0;
}