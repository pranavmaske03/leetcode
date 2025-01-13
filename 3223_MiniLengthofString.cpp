#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int minimumLength(string s) 
        {
            vector<int> char_freq(26,0);

            for(int i = 0; i < s.length(); i++) 
            {
                int code = s[i] - 97;
                char_freq[code]++;
                if(char_freq[code] == 3)
                {
                    char_freq[code] = 1;
                }
            }
            int length = 0;
            for(int i = 0; i < 26; i++) 
            {
                length += char_freq[i];
            }
            return length;
        }
};

int main()
{
    string s = "ecdxxxxhhhhhhhhhhhhhhbbfgfujjiisssjsjjs";

    Solution obj;
    int ret = obj.minimumLength(s);
    cout<<"length is : "<<ret;
    

    return 0;
}
