#include<iostream>
using namespace std;

class Solution 
{
    public:
        string clearDigits(string s) 
        {
            string result = "";
            for(int i = 0; i < s.size(); i++)
            {
                if(isdigit(s[i])&& !result.empty()) {
                    result.pop_back();
                } else {
                    result += s[i];
                }
            }            
            return result;
        }
};

int main()
{

    return 0;
}