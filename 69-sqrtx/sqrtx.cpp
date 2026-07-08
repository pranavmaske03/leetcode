class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int sqr_root = 0;

        if(x == 0 || x == 1)
            return x;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(mid <= (x / mid)) {
                sqr_root = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return sqr_root;
    }
};