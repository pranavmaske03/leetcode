#include<iostream>
#include<vector>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
    }
};

int main() {

    return 0;
}