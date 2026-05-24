#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> res;
        int count = 0;
        int curr = INT_MIN;

        for(int num : nums) {
            if(num != curr) {
                curr = num;
                count = 1;
            } else {
                count++;
            }
            if(count <= k) {
                res.push_back(num);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4};
    int k = 2;
    vector<int> result = sol.limitOccurrences(nums, k);
    for(int num : result) {
        cout << num << " ";
    }
    return 0;
}