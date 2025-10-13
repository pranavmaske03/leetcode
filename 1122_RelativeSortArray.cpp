#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
        {
            vector<int> freq(1001,0);
            int i = 0,j = 0;

            // count the frequency of each elment
            for(i = 0; i < arr1.size(); i++) {
                freq[arr1[i]]++;
            }

            // put element as per the order into the arr1
            for(i = 0,j = 0; i < arr2.size(); i++) {
                while(freq[arr2[i]] > 0) {
                    arr1[j++] = arr2[i];
                    freq[arr2[i]]--;
                }
            }

            // put element in ascending order which are not present in arr2;
            for (i = 0; i <= 1000; i++) {
                while (freq[i] > 0) {
                    arr1[j++] = i;
                    freq[i]--;
                }
            }

            return arr1;
        }
};

int main()
{

    return 0;
}