#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int minimumLength(string s) 
        {
            vector<int> freq(26,0);
            int count = 0;

            for(auto& ch : s) {
                freq[ch - 'a']++;
            }

            for(int i = 0; i < 26; i++)
            {
                if(freq[i] % 2 == 1) {
                    count++;
                } else if(freq[i] > 0) {
                    count += 2;
                }
            }
            return count;
        }
};

int main()
{

    return 0;
}