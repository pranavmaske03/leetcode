#include<iostream>
#include<unordered_map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for (auto &it : freq) {
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;
        for (int i = n; i >= 0 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }
        return ans;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int& num : nums) mp[num]++;
        priority_queue<pair<int,int> ,vector<pair<int , int>> , greater<>>pq;

        for(auto& [val, freq] : mp) {
            pq.push({freq, val});
            if(pq.size() > k) pq.pop();
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
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