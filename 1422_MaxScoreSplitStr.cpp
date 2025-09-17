#include<iostream>
using namespace std;

class Solution 
{
    public:
        int maxScore(string s) 
        {
            int ans = 0;
            int ones = 0,zeros = 0;

            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '1') {
                    ones++;
                }
            }
            for(int i = 0; i < s.length()-1; i++) {
                if(s[i] == '1') {
                    ones--;
                } else {
                    zeros++;
                }
                ans = max(ans,(zeros+ones));
            }
            return ans;
        }
};

int main()
{

    return 0;
}