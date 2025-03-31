#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int findMaxLength(vector<int> nums) {
            unordered_map<int,int> map;
            int len = 0,maxLen = 0;

            for(int i = 0; i < nums.size(); i++) {
                sum += (nums[i] == 0) ? -1 : 1;
                if(map.find(sum) != mp.end()) {
                    maxLen = (maxLen,i - map[sum]);
                } else {
                    map[sum] = i;
                }
            }
            return maxLen;
        }
};

int main() 
{
    vector<int> nums = {0,1,1,1,1,1,0,0,0};

    Solution obj;
    cout<<obj.findMaxLength(nums);
    
    return 0;
}