#include<iostream>
using namespace std;

class Solution 
{
    public:
        int reverseDegree(string s) 
        {
            int sum = 0;

            for(int i = 0; i < s.length(); i++) 
            {
                int reverseIdx =  26 - (s[i] - 'a');
                sum += reverseIdx * (i + 1);
            }
            return sum;
        }
};

int main()
{

    return 0;
}