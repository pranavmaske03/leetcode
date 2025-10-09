#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int sumOddLengthSubarrays(vector<int>& arr) 
        {
            long long totalSum = 0,prefixSum = 0;

            for(int i = 0; i < arr.size(); i++)
            {
                prefixSum += arr[i];
                
                // only consider odd length subarrays
                if((i+1) % 2 == 1) {
                    int left = 0;
                    int right = i+1;
                    int currSum = prefixSum;

                    // add first window
                    totalSum += prefixSum;
                    while(right < arr.size()) {
                        currSum += arr[right++];
                        currSum -= arr[left++];
                        totalSum += currSum;
                    }
                }
            }
            return totalSum;
        }
        // using formula
        int sumOddLengthSubarrays1(vector<int>& arr) 
        {
            long long totalSum = 0;
            int n = arr.size();

            for (int i = 0; i < n; i++) {
                int left = i + 1;        
                int right = n - i;      
                int total = left * right;
                
                int oddCount = (total + 1) / 2;

                totalSum += (long long)arr[i] * oddCount;
            }
            return totalSum;
    }
};

int main()
{

    return 0;
}