#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;

        auto backtrack = [&](auto&& backtrack, int start) -> void {
            if (sub.size() >= 2) {
                res.push_back(sub);
            }
            if (start == nums.size())
                return;

            unordered_set<int> st;
            for (int i = start; i < nums.size(); i++) {
                if (st.count(nums[i]))
                    continue;
                if (sub.empty()) {
                    st.insert(nums[i]);
                    sub.push_back(nums[i]);
                    backtrack(backtrack, i + 1);
                    sub.pop_back();
                } else if (nums[i] >= sub.back()) {
                    st.insert(nums[i]);
                    sub.push_back(nums[i]);
                    backtrack(backtrack, i + 1);
                    sub.pop_back();
                }
            }
        };

        backtrack(backtrack, 0);
        return res;
    }
};

int main()
{
    return 0;
}