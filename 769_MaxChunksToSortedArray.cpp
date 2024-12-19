#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int maxChunksToSorted(vector<int>& arr) 
        {
            int prefixSum = 0,sum = 0, chunks = 0;    

            for(int i = 0; i < arr.size(); i++)
            {
                prefixSum += arr[i];
                sum += i;

                if(prefixSum == sum) {
                    chunks++;
                }
            }
            return chunks;
        }
};

int main()
{


    return 0;
}