#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int minCost(string colors, vector<int>& neededTime) 
        {
            int lowTime = 0;
            int Max = neededTime[0];

            for(int i = 1; i < colors.size(); i++)
            {
                if(colors[i-1] == colors[i]) {
                    lowTime += min(Max,neededTime[i]);
                    Max = max(Max,neededTime[i]);
                } else {
                    Max = neededTime[i];
                }
            }
            return lowTime;
        }
};

int main()
{

    return 0;
}