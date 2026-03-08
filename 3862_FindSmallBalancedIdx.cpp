#include<iostream>  
#include<vector>
using namespace std;

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> prefSum(n, 0);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefSum[i] = prefSum[i - 1] + nums[i];

        vector<long long> sufProd(n, 1);
        sufProd[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] != 0 && sufProd[i + 1] > LLONG_MAX / nums[i])
                sufProd[i] = LLONG_MAX;  
            else
                sufProd[i] = (long long)nums[i] * sufProd[i + 1];
        }

        for (int i = 0; i < n; i++) {
            long long leftSum   = (i == 0)     ? 0 : prefSum[i - 1];
            long long rightProd = (i == n - 1) ? 1 : sufProd[i + 1];

            if (leftSum == rightProd)
                return i;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.smallestBalancedIndex(nums) << endl; // Output: -1
    return 0;
}