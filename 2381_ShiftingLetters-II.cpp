#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        string shiftingLetters(string s, vector<vector<int>>& shifts) 
        {
            int n = s.length();
            vector<int> diff(n+1,0);

            for(int i = 0; i < shifts.size(); i++)
            {
                int start = shifts[i][0];
                int end = shifts[i][1];
                int dir = shifts[i][2];

                int add = (dir == 1) ? 1 : -1;

                diff[start] += add;
                diff[end+1] -= add;
            }

            int currSum = 0;
            for(int i = 0; i < n; i++)
            {
                currSum = (currSum + diff[i]) % 26;
                if(currSum < 0) currSum += 26;

                int pos = s[i] - 'a';
                pos = (pos + currSum) % 26;
                s[i] = char(pos + 'a');
            }
            return s;
        }
};

int main()
{

    return 0;
}