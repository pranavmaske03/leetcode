#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if(sentence[0] != sentence[n-1]) return false;

        for(int i=1; i<n-1; i++){
            if(sentence[i] == ' '){
                if(sentence[i-1] != sentence[i+1]) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string test1 = "leetcode exercises sound delightful";
    string test2 = "eetcode exercises sound delightful";
    cout << boolalpha;  // Print boolean values as true/false
    cout << solution.isCircularSentence(test1) << endl;  // Expected: true
    cout << solution.isCircularSentence(test2) << endl;  // Expected: false
    return 0;
}