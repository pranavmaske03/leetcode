#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int minMoves(vector<int>& nums) 
        {
            int minVal = INT_MAX;
            int minMoves = 0;

            for(int& num : nums) minVal = min(num, minVal);
            for(int& num : nums) minMoves += num - minVal;

            return minMoves;
        }
};

int main()
{
    return 0;
}