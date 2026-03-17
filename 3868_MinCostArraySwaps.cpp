#include<iostrem>
#include<vector>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int maxv = 0;
        for (int x : nums1) maxv = max(maxv, x);
        for (int x : nums2) maxv = max(maxv, x);
        vector<int> tot(maxv + 1, 0), c1(maxv + 1, 0);
        for (int i = 0; i < n; ++i) {
            ++tot[nums1[i]];
            ++tot[nums2[i]];
            ++c1[nums1[i]];
        }

        long long ans = 0;
        for (int v = 1; v <= maxv; ++v) {
            if (tot[v] % 2) return -1;
            int target = tot[v] / 2;
            if (c1[v] > target) ans += c1[v] - target;
        }
        return (int)ans;
    }
};

int main()
{

    return 0;
}