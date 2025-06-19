#include<iostream>
#include<unordered_map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) 
        {
            unordered_map<int,int> freq;
            vector<int> result;

            for(auto& num : nums) {
                freq[num]++;
            }

            vector<pair<int,int>> vec(freq.begin(),freq.end());
            sort(vec.begin(),vec.end(),[](const auto &a, const auto &b){
                return a.second > b.second;
            });

            for(size_t i = 0; i < vec.size() && k--; ++i) {
                cout << vec[i].first << " " << vec[i].second << "\n";
                result.push_back(vec[i].first);
            }

            return result;
        }
};

int main()
{
    vector<int> nums{1,1,1,2,2,3};
    int k = 2;
    Solution obj;
    obj.topKFrequent(nums,k);

    return 0;
}