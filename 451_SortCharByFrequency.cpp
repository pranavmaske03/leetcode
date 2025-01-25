#include<iostream>
#include<unordered_map>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        string frequencySort(string s) 
        {
            unordered_map<char,int> char_freq;

            for(char ch : s) {
                char_freq[ch]++;
            }
             std::vector<std::pair<char, int>> vec(char_freq.begin(), char_freq.end());

            // Sort the vector by keys
            std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
                return a.second > b.second;
            });

            string result = "";
            for(auto pair : vec) {
                char ch = pair.first;
                int freq = pair.second;
                while(freq--) {
                    result += ch;
                }
            }

            return result;   
        }
        
        string frequencySort1(string s) 
        {

            // Count the frequency of each character
            unordered_map<char, int> freq;
            for (char c : s) {
                freq[c]++;
            }
            
            // Create buckets where index represents frequency
            vector<string> buckets(s.size() + 1); // max frequency = s.size()
            for (auto& [ch, count] : freq) {
                buckets[count] += string(count, ch);
            }
            
            // Build the result from buckets in reverse order
            string result = "";
            for (int i = s.size(); i > 0; --i) {
                if (!buckets[i].empty()) {
                    result += buckets[i];
                }
            }
            return result;
        }
};

int main()
{
    Solution obj;
    cout<<obj.frequencySort("aaabbcccddeeffggghhiiiijjkkll");

    return 0;
}