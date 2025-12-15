#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isPrefixString(string s, vector<string>& words) 
        {
            int pos = 0;

            for (auto& word : words) {
                if (s.compare(pos, word.size(), word) != 0) {
                    return false;
                }
                pos += word.size();
                if (pos == s.size()) return true;
            }
            return false;
        }
        bool isPrefixString1(string s, vector<string>& words) 
        {
            string res = "";
            res.reserve(s.size());

            for(auto& word : words) {
                res += word;
                if(res == s) return true;
                if(res.size() > s.size()) return false;
            }
            return false;
        }
};

int main()
{

    return 0;
}