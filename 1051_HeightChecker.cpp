#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int heightChecker(vector<int>& heights) 
        {
            vector<int> aux = heights;
            sort(aux.begin(),aux.end());
            int mismatch = 0;

            for(int i = 0; i < heights.size(); i++)
            {
                if(heights[i] != aux[i]) mismatch++;
            }
            return mismatch;
        }
};

int main()
{
    return 0;
}