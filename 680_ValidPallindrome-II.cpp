#include<iostream>
using namespace std;

class Solution 
{
    public:
        bool isPallindrome(string s,int left ,int right) 
        {
            while(left < right) {
                if(s[left] != s[right]) {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }

        bool validPalindrome(string s) 
        {
            int left = 0,right = s.length()-1;

            while(left < right) 
            {
                if(s[left] != s[right]) {
                    return isPallindrome(s,left+1,right) || isPallindrome(s,left,right-1);
                }
                left++;
                right--;
            }
            return true;
        }
};

int main()
{

    return 0;
}