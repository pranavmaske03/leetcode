#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
        {
            sort(arr2.begin(),arr2.end());
            int count = 0;
            int n = arr1.size();
            int m = arr2.size();

            for(int i = 0; i < n; i++) 
            {
                int start = 0;
                int end = m-1;

                while(start <= end) {
                    int mid = start + (end - start)/2; 

                    int sub = abs(arr1[i] - arr2[mid]);
                    if(sub <= d) {
                        count++;
                        break;
                    }
                    if(arr2[mid] < arr1[i]) {
                        start = mid + 1;
                    } else {    
                        end = mid - 1;
                    }
                }
            }
            return (n - count);
        }
};

int main()
{
    vector<int> arr1{4,5,8},arr2{10,9,1,8};
    int d = 2;
    Solution obj;
    cout<<obj.findTheDistanceValue(arr1,arr2,d)<<endl;

    return 0;
}