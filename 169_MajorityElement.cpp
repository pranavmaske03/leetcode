#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int majorityElement(vector<int>& nums) 
        {
            unordered_map<int,int> map;
            int maxFreq = 0;
            int majority = 0;

            for(auto val : nums) {
                map[val]++;
            }

            for(const auto& pair : map) {
                if(pair.second > maxFreq) {
                    maxFreq = pair.second;
                    majority = pair.first;
                }
            }
            return majority;
        }
};

int main()
{
    vector<int> nums{2,2,1,1,1,2,2};
    Solution obj;
    cout<<obj.majorityElement(nums);

    return 0;
}