class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftSum = height[0];
        int rightSum = height[n - 1];
        int res = 0,left = 0, right = n - 1;

        while(left < right) {
            if(leftSum < rightSum) {
                left++;
                leftSum = max(leftSum, height[left]);
                res += leftSum - height[left];
            } else {
                right--;
                rightSum = max(rightSum, height[right]);
                res += rightSum - height[right];
            }
        }
        return res;
    }
};