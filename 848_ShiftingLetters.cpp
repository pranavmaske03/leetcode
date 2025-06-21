#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        long long shiftSum = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            shiftSum = (shiftSum + shifts[i]) % 26;
            int idx = int(s[i] - 'a');
            s[i] = 'a' + (idx + shiftSum) % 26;
        }
        return s;
    }
};


int main()
{

    return 0;
}