#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool canConstruct(string r, string m) 
        {
            vector<int> check(26,0);

            for(auto& ch : m) { 
                check[ch - 'a']++;
            }

            for(int i = 0; i < r.length(); i++)
            {
                if(--check[r[i] - 'a'] < 0) {
                    return false;
                }
            }
            return true;
        }
};

int main()
{

    return 0;
}