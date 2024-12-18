#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
    public:
        vector<int> finalPrices(vector<int>& prices) 
        {
            for(int i = 0; i < prices.size()-1; i++)                
            {
                int j = i+1;
                // find the small price index after the ith index
                while(j < prices.size() && prices[j] > prices[i]) {
                    j++;
                }
                if(j < prices.size() && prices[j] <= prices[i]) {
                    prices[i] -= prices[j];   
                }  
            }
            return prices; 
        }
};

int main()
{
    vector<int> prices = {10,1,1,6};

    Solution obj;
    obj.finalPrices(prices);

    return 0;
}