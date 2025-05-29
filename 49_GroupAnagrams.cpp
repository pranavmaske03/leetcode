#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            unordered_map<string, vector<string>> groups;            
            vector<vector<string>> result;

            for(const auto& str : strs) {
                vector<int> char_freq(26,0);

                for(const char& ch : str)             {
                    char_freq[ch - 'a']++;
                }
                string key = "";
                for(auto& freq : char_freq) {
                    key += to_string(freq) + "-";
                }
                groups[key].push_back(str);
                key.clear();
            }
            for(const auto& [key,values] : groups) {
                result.push_back(values);
            }
            return result;
        }
};

int main()
{
    vector<string>  strs = {"eat","tea","tan","ate","nat","bat"};
    Solution obj;

    obj.groupAnagrams(strs);

    return 0;
}