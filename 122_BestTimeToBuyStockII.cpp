#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int maxProfit(vector<int>& prices) {
            int maxProfit = 0;
            int buy = prices[0];
            bool flag = true;

            for(int i = 1; i < prices.size(); i++) {
                if(buy > prices[i] && flag) {
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
};

int main()
{
    vector<int> prices = {1,2,3,4,5};
    Solution obj;
    cout<<obj.maxProfit(prices)<<endl;

    return 0;
}