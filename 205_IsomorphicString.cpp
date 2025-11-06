#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isIsomorphic(string s, string t) 
        {
            if(s.length() != t.length()) return false;
            vector<int> map_t_to_s(256,-1),map_s_to_t(256,-1);

            for(int i = 0; i < s.length(); i++)
            {
                int ch1 = s[i];
                int ch2 = t[i];

                if(map_s_to_t[ch1] != -1 && map_s_to_t[ch1] != ch2 || map_t_to_s[ch2] != -1 && map_t_to_s[ch2] != ch1) {
                    return false;
                }
                map_s_to_t[ch1] = ch2;
                map_t_to_s[ch2] = ch1;
            }
            return true;
        }
};


int main()
{

    return 0;
}