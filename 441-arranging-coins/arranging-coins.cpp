class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0, right = n;
        int res = 0;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            long long coins = 1LL * mid * (mid + 1) / 2;

            if(coins <= n) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};