#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int secondHighest(string s) 
        {
            int largest = -1,secondLargest = -1;
            
            for(char ch : s) {
                if(isdigit(ch)) {
                    int digit = ch - '0';
                    if(largest < digit) {
                        secondLargest = largest;
                        largest = digit;
                    } else if(digit < largest && digit > secondLargest) {
                        secondLargest = digit;
                    }
                }
            }
            return secondLargest;
        }
};

int main()
{
    string str = "sxih23583";
    Solution obj;
    cout<<obj.secondHighest(str)<<"\n"; 

    return 0;
}