#include<iostream>
using namespace std;

class Solution {
    public:
        string reversePrefix(string word, char ch) {
            int left = 0,right = 0;
            for(int i = 0; i < word.length(); i++)
            {
                if(word[i] == ch) 
                {
                    right = i;
                    break;
                }
            }
            while(left <= right) {
                char temp = word[left];
                word[left] = word[right];
                word[right] = temp;

                left++;
                right--;
            }
            return word;
        }
};

int main()
{

    return 0;
}