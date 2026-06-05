#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    // Hash Map
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> res;
        int target = nums.size() / 3;

        for(int& num : nums) {
            mp[num]++;
        }

        for(auto& [key, val] : mp) {
            if(val > target) {
                res.push_back(key);
            }
        }
        return res;
    }
    // Boyer-Moore Voting Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ans1 = INT_MIN, ans2 = INT_MIN;   

        for(int i = 0; i < nums.size(); i++) {
            if(cnt1 == 0 && ans2 != nums[i]) {
                cnt1++;
                ans1 = nums[i];
            } else if(cnt2 == 0 && ans1 != nums[i]) {
                cnt2++;
                ans2 = nums[i];
            } else if(nums[i] == ans1) {
                cnt1++;
            } else if(nums[i] == ans2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        int target = nums.size() / 3;

        for(int& num : nums) {
            if(num == ans1) cnt1++;
            if(num == ans2) cnt2++;
        }
        if(cnt1 > target) ans.push_back(ans1);
        if(cnt2 > target) ans.push_back(ans2);

        return ans;
    }
};
    
int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3};
    vector<int> result = sol.majorityElement(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}