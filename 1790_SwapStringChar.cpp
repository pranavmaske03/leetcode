#include<iostream>
using namespace std;

class Solution 
{
    public:
        bool areAlmostEqual(string s1, string s2) {
            int swap = 0;
            char ch1 = '\0',ch2 = '\0';
            for(int i = 0; i < s1.size(); i++) 
            {
                if(s1[i] != s2[i])
                {
                    swap++;
                    if(swap == 1) {
                        ch1 = s1[i];
                        ch2 = s2[i];
                    }
                    else if(swap == 2) {
                        if(ch1 != s2[i] || ch2 != s1[i]) return false;
                    }

                }
            }
            return swap == 0 || swap == 2;
        }
};

int main()
{

    return 0;
}