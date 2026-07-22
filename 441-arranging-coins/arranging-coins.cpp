class Solution {
public:
    int arrangeCoins(int n) {
        long long coins = 0;
        int res = 0;

        for(int i = 1; i <= n; i++) {
            coins += i;
            if(coins > n) {
                break;
            }
            res++;
        }
        return res;
    }
};