#include<stdio.h>

int max(int num1,int num2)
{
    return num1 > num2 ? num1 : num2;
}

double findMaxAverage(int* nums, int numsSize, int k) 
{
    double sum = 0,max_sum = 0;

    for(int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    max_sum = sum;
    for(int i = k; i < numsSize; i++)
    {
        sum = sum - nums[i-k] + nums[i];
        max_sum = (sum > max_sum) ? sum : max_sum;
    }
    return max_sum / k;
}

int main()
{
    int arr[] = {1,12,-5,-6,50,3};

    printf("%f\n",findMaxAverage(arr,6,4));

    return 0;
}