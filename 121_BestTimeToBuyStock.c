#include<stdio.h>

int maxProfit(int* prices, int pricesSize) 
{
    int max_profit = 0;
    int buy = prices[0];
    int sell = 0;

    for(int i = 1; i < pricesSize; i++)
    {
        if(buy > prices[i])
        {
            buy = prices[i];
        }
        sell = prices[i] - buy;
        if(max_profit < sell)
        {
            max_profit = sell;
        }
    }
    return max_profit;
}

int main()
{
    int arr[10] = {6,3,1,5,6,3,9,2,1,5};

    int ret = maxProfit(arr,10);
    printf("Maximum profit is : %d\n",ret);

    return 0;
}