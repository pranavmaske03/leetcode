#include<iostream>
using namespace std;

class Solution 
{
    public:
        string capitalizeTitle(string t) 
        {
            int n = t.length();
            int left = 0,right = 0;

            while(right < n) 
            {
                if(t[right] == ' ') {
                    if(right - left > 2) {
                        t[left] = toupper(t[left]);
                    }
                    left = right + 1;
                } else {
                    t[right] = tolower(t[right]);
                }
                right++;
            }
            if(right - left > 2) {
                t[left] = toupper(t[left]);
            }
           
            return t;
        }
};


int main()
{

    return 0;
}