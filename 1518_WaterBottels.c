#include<stdio.h>

int numWaterBottles(int numBottles, int numExchange) 
{  
    int total_bottals = numBottles + (numBottles/numExchange);
    int result = (numBottles/numExchange) + (numBottles%numExchange);
    while((result/numExchange + result%numExchange) >= numExchange)
    {
        total_bottals = total_bottals + (result/numExchange);
        result = (result/numExchange) + (result%numExchange);
    }
    total_bottals = total_bottals + (result/numExchange);

    return total_bottals;
}

int main()
{
    int ret = numWaterBottles(86,3);
    printf("%d\n",ret);

    return 0;
}

// return ((numBottles*numExchange)-1) / (numExchange-1);