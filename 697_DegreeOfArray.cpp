#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

struct Info
{
    int freq = 0;
    int firstIdx = -1;
    int lastIdx = -1;
};

class Solution 
{
    public:
        int findShortestSubArray(vector<int>& nums) 
        {
            unordered_map<int,Info> mp;
            int minLen = INT_MAX;
            int degree = 0;

            for(int i = 0; i < nums.size(); i++) 
            {
                int num = nums[i];
                if(!mp.count(num)) {
                    mp[num].firstIdx = mp[num].lastIdx = i;
                } else {
                    mp[num].lastIdx = i;
                }
                mp[num].freq++;
            }
            for (auto &p : mp) {
                Info value = p.second;
                int len = value.lastIdx - value.firstIdx + 1;

                if(value.freq > degree) {
                    degree = value.freq;
                    minLen = len;         
                }
                else if(value.freq == degree) {
                    minLen = min(minLen, len);
                }
            }
            return minLen;
        }
};

int main()
{

    return 0;
}