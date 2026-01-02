#include<iostream>
using namespace std;

class Solution 
{
    public:
        char solve(int len, int k)
        {
            if(len == 1) return 'a';
            int half = len / 2;

            if(k <= half) {
                return solve(half,k);
            } else {
                char ch = solve(half,k - half);
                return ch == 'z' ? 'a' : ch + 1;
            }
        }

        char kthCharacter(int k) 
        {
            int len = 1;
            while(len < k) len *= 2;
            return solve(len,k);
        }
};

int main()
{

    return 0;
}