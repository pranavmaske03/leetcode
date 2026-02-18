#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int backtrack(vector<int>& nums, int k, unordered_map<int,int>& freq, int i)
    {
        if(i == nums.size()) return 1;

        int result = backtrack(nums, k, freq, i + 1); // nums[i] not taken
        if(!freq[nums[i] - k] && !freq[nums[i] + k]) {
            freq[nums[i]]++;
            result += backtrack(nums, k, freq, i + 1); // nums[i] taken
            freq[nums[i]]--;
        }
        return result;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        return backtrack(nums, k, freq, 0) - 1;
    }
};

int main()
{
    return 0;
}