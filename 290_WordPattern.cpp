#include<iostream>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        bool wordPattern(string pattern, string s) 
        {
            unordered_map<char,string> map1;
            unordered_map<string,char> map2;
            string word = "";

            stringstream ss(s);
            for(int i = 0; i < pattern.size(); i++)
            {
                char ch = pattern[i];
                if(!(ss >> word)) return false;
                if(map1.count(ch) && map1[ch] != word) return false;
                if(map2.count(word) && map2[word] != ch) return false;

                map1[ch] = word;
                map2[word] = ch;
            }
            if(ss >> word) return false;
            return true;
        }
};

int main()
{

    return 0;
}