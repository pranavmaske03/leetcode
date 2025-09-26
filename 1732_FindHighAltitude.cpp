#include<iostream>
using namespace std;

class Solution 
{
    public:
        int largestAltitude(vector<int>& gain) 
        {
            int highAltitude = 0,prefixSum = 0;

            for(int i = 0; i < gain.size(); i++)
            {
                prefixSum += gain[i];
                highAltitude = max(highAltitude,prefixSum);
            }
            return highAltitude;
        }
};

int main()
{

    return 0;
}