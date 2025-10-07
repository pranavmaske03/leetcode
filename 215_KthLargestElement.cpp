#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        int findKthLargest(vector<int>& nums, int k) 
        {
            unordered_map<int,int> mp;
            int max = 0,min = 0;

            for(int i = 0; i < nums.size(); i++) {
                max = max < nums[i] ? nums[i] : max;
                min = min > nums[i] ? nums[i] : min;
            }
            max -= min;

            for(int i = 0; i < nums.size(); i++) {
                mp[nums[i] - min]++;
            }

            for(int i = max; i >= 0; i--) {
                if(mp.find(i) != mp.end()) {
                    while(mp[i] > 0 && k > 0) {
                        max = i + min;
                        mp[i]--;
                        k--;
                    }
                }
            }
            return max;
        }
};

int main()
{

    return 0;
}