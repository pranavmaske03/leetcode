#include<iostream>
using namespace std;

class Solution 
{
    public:
        string getEncryptedString(string s, int k) 
        {
            string res = "";
            int n = s.length();

            for(int i = 0; i < s.length(); i++)
            {
                res += s[(i + k) % n];
            }
            return res;
        }
};

int main()
{

    return 0;
}