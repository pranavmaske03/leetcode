#include<iostream>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            // Move left pointer to the next alphabetical character
            if (!isalpha(s[left])) {
                left++;
                continue;
            }
            // Move right pointer to the previous alphabetical character
            if (!isalpha(s[right])) {
                right--;
                continue;
            }
            // Swap the characters at left and right pointers
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};

int main()
{

    return 0;
}