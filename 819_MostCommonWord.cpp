#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> map;
        vector<string> words;
        int left = 0;
        while (left < paragraph.size()) {
            string temp;
            while (left < paragraph.size() && !isalpha(paragraph[left])) {
                left++;
            }
            while (left < paragraph.size() && isalpha(paragraph[left])) {
                temp.push_back(tolower(paragraph[left]));
                left++;
            }
            words.push_back(temp);
            map[temp]++;
        }
        for (string word : banned) {
            map[word] = 0;
        }
        int freq = 0;
        string ans = "";
        for (string word : words) {
            if (map[word] > freq) {
                freq = map[word];
                ans = word;
            }
        }
        return ans;
    }
};
    
int main() {
    Solution sol;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    cout << sol.mostCommonWord(paragraph, banned) << endl;
    return 0;
}