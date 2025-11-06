#include<iostream>
using namespace std;

class Solution 
{
    public:
        int numDecodings(string s) 
        {
            if(s.empty() || s[0] == '0') return 0;

            int prev = 1,curr = 1;
            for(int i = 1; i < s.length(); i++)            
            {
                int temp = 0;
                if(s[i] != '0') temp += curr;

                int two = stoi(s.substr(i-1, 2));
                if(two >= 10 && two <= 26) temp += prev;

                prev = curr;
                curr = temp;
            }
            return curr;
        }
};

int main()
{

    return 0;
}