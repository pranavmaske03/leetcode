#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxVal = INT_MIN;
        vector<int> prefixGcd;

        for (int i = 0; i < nums.size(); i++) {
            maxVal = max(maxVal, nums[i]);
            prefixGcd.push_back(std::gcd(nums[i], maxVal));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int left = 0, right = prefixGcd.size() - 1;
        long long sum = 0;
        while (left < right) {
            int a = prefixGcd[left++];
            int b = prefixGcd[right--];

            sum += std::gcd(a, b);
        }
        return sum;
    }
};

int main()
{
    return 0;
}