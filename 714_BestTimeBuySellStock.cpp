#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            vector<int> curr(2, 0), next(2, 0);

            for(int idx = n - 1; idx >= 0; idx--) {
                //For canBuy = true
                curr[1] = max(-prices[idx] + next[0], next[1]);
                //For canBuy = false
                curr[0] = max(prices[idx] - fee + next[1], next[0]);
                next = curr;
            }

            return next[1];
        }
};

int main()
{
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    Solution obj;
    cout<<obj.maxProfit(prices,fee);

    return 0;
}