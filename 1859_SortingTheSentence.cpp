#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10);   
        string word;

        stringstream ss(s);
        while (ss >> word) {
            int pos = word.back() - '1';  
            word.pop_back();           
            words[pos] = word;
        }

        string result = "";
        for (int i = 0; i < 10; i++) {
            if (words[i].empty()) break;
            if (!result.empty()) result += " ";
            result += words[i];
        }

        return result;
    }
};


int main()
{

    return 0;
}