#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) 
        {           
            vector<pair<int,int>>hash(nums.size());
            for(int i = 0; i < nums.size(); i++) {
                hash[i].first = i;
                hash[i].second = nums[i];
            }
            sort(hash.begin(), hash.end(), [](auto &a, auto &b){
                return a.second < b.second; // sort by value
            });   
            for(int i = 1; i < hash.size(); i++) {
                if(hash[i-1].second == hash[i].second && k >= abs(hash[i - 1].first - hash[i].first))
                {
                    return true;
                }
            }
            return false;
        }
        
        // Another variation
        bool containsNearbyDuplicate1(vector<int>& nums, int k) 
        {           
            unordered_map<int,int> visit;

            for(int i = 0; i < nums.size(); i++)
            {
                if(visit.find(nums[i]) != visit.end() && k >= abs(i - visit[nums[i]]))
                {
                    return true;
                }
                visit[nums[i]] = i;
            }
            return false;
        }
};

int main()
{
    vector<int> nums{1,2,3,1,2,3};
    int k = 2;
    Solution obj;
    obj.containsNearbyDuplicate(nums,k);

    return 0;
}