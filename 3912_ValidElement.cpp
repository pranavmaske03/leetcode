#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> res;
        vector<bool> check(nums.size(), false);
        int currMax = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(currMax < nums[i]) {
                check[i] = true;
                currMax = nums[i];
            }
        }

        currMax = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(currMax < nums[i]) {
                check[i] = true;
                currMax = nums[i];
            }
        }

        for(int i = 0; i < check.size(); i++) {
            if(check[i]) {
                res.push_back(nums[i]);
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 4, 2, 5};
    vector<int> validElements = sol.findValidElements(nums);

    for(int num : validElements) {
        cout << num << " ";
    }
    return 0;
}