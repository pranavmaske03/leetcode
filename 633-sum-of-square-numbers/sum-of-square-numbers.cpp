class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0, right = sqrt(c);

        while(left <= right) {
            long long square = (left * left) + (right * right);

            if(square == c) 
                return true;
            
            if(square < c) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};