#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int singleNumber(vector<int>& nums) 
        {
            unordered_map<int,int> freq;
            int single_number = 0;

            for(auto val : nums) 
            {
                freq[val] += 1;
            }

            for (auto& [num, count] : freq) {
                if(count == 1) single_number = num;
            }
            return single_number;
        }
};

int main()
{
    vector<int> nums = {0,1,0,1,0,1,99};
    Solution obj;
    cout<<obj.singleNumber(nums);
    return 0;
}
