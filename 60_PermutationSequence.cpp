#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums;
        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k -= 1;
        string ans = "";
        while (!nums.empty()) {
            int index = k / fact;
            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            if (nums.empty()) break;
            k %= fact;
            fact /= nums.size();
        }
        return ans;
    }
};

int main()
{
    return 0;
}