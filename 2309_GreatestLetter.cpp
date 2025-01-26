#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        string greatestLetter(string s) 
        {
            vector<int>map_capital(26,0)    ;
            vector<int>map_small(26,0);

            for(auto ch : s) {
                if(ch >= 'a' && ch <= 'z') {
                    map_small[ch - 'a']++;
                }
                else {
                    map_capital[ch - 'A']++;
                }
            }
            string letter = "";
            for(int i = 0; i < 26; i++)
            {
                if(map_small[i] != 0 && map_capital[i] != 0) {
                    letter = char('A'+i);
                }
            }
            return letter;
        }
};
int main()
{
    Solution obj;
    cout<<obj.greatestLetter("AbCdEfGhIjK");    

    return 0;
}