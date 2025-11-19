#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
        {
            vector<bool> res;
            int maxCandies = INT_MIN;

            for(int i = 0; i < candies.size(); i++) {
                maxCandies = max(maxCandies,candies[i]);
            }
            for(int i = 0; i < candies.size(); i++)
            {
                if(maxCandies > candies[i] + extraCandies) {
                    res.push_back(false);
                } else {
                    res.push_back(true);
                }
            }
            return res;
        }
};

int main()
{

    return 0;
}