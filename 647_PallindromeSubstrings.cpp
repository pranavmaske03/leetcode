#include<iostream>
using namespace std;

class Solution 
{
    public:
        int expand(string &s , int left ,int right)
        {   
            int count = 0;
            while(left >= 0 &&  right < s.size())
            {
                if(s[left] == s[right]) {
                    count++;
                } else {
                    break;
                }
                left--,right++;
            }
            return count;
        }
        int countSubstrings(string s) 
        {
            int totalCount = 0;
            for(int i = 0; i < s.length(); i++)
            {
                totalCount += expand(s , i, i);
                totalCount += expand(s, i, i+1);
            }
            return totalCount;
        }
};

int main()
{

    return 0;
}