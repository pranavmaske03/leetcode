#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int maxProfit(vector<int>& prices) {
            int maxProfit = 0;
            int buy = prices[0];

            for(int i = 1; i < prices.size(); i++) {
                if(buy > prices[i]) {
                    buy = prices[i];
                    continue;
                }
                int j = i;
                while(j+1 < prices.size() && prices[j] < prices[j+1]) {
                    j++;
                }
                maxProfit += (prices[j] - buy);
                buy = prices[j];
                i = j;
            }
            return maxProfit;
        }

        int maxProfit1(vector<int>& prices) {
            int maxProfit = 0;
          
            for(int i = 1; i < prices.size(); i++) 
            {
                if(prices[i] > prices[i-1])
                {
                    maxProfit += (prices[i] - prices[i-1]);
                }
            }
            return maxProfit;
        }
};

int main()
{
    vector<int> prices = {1,2,3,4,5};
    Solution obj;
    cout<<obj.maxProfit1(prices)<<endl;

    return 0;
}