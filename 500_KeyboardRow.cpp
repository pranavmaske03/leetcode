#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        vector<string> findWords(vector<string>& words) {
            vector<string> result;

           
            unordered_set<char> firstRow = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                                            'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
            unordered_set<char> secondRow = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                                            'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
            unordered_set<char> thirdRow = {'z', 'x', 'c', 'v', 'b', 'n', 'm',
                                            'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

            for (const string& word : words) {
                bool isFirstRow = true, isSecondRow = true, isThirdRow = true;

                for (char c : word) {
                    if (!firstRow.count(c)) isFirstRow = false;
                    if (!secondRow.count(c)) isSecondRow = false;
                    if (!thirdRow.count(c)) isThirdRow = false;
                }

                if (isFirstRow || isSecondRow || isThirdRow) {
                    result.push_back(word);
                }
            }
            return result;
        }
};


int main() 
{
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"}; 
    Solution obj;
    vector<string> result = obj.findWords(words);

    cout << "Words that can be typed using one row of the keyboard:" << endl;
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
