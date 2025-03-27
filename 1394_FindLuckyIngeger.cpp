#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int findLucky(vector<int>& arr) {
            unordered_map<int,int> freq;

            int n = arr.size();
            int lucky = -1;

            for(int val : arr){
                freq[val]++;
            }

            for(auto val : freq){
                if(val.first == val.second){
                    lucky = max(lucky,val.first);
                }
            }
            return lucky;            
        }
};

int main() 
{
    vector<int> arr = {2,2,3,3,4};
    Solution obj;
    cout<< obj.findLucky(arr);
    return 0;
}