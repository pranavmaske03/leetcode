#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int maxProfit(vector<int>& prices) 
        {
            int profit = 0,buy = prices[0];

            for(int i = 1; i < prices.size(); i++)
            {
                if(buy > prices[i]) 
                {
                    buy = prices[i];
                }
                if(profit < prices[i] - buy) 
                {
                    profit = prices[i] - buy;
                }
            }
            return profit;
        }
};

int main()
{
    return 0;
}