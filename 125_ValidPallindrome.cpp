#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1;

        while(start < end) {
            while (start < end && !isalnum(s[start])) start++;
            while (start < end && !isalnum(s[end])) end--;
        
            if (start < end && tolower(s[start]) != tolower(s[end])) return false;
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string test = "A man, a plan, a canal: Panama";
    cout << (solution.isPalindrome(test) ? "True" : "False") << endl;
    return 0;
}