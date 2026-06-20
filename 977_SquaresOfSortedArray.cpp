#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int left = 0, right = n - 1;
        int last = n - 1;

        while(left <= right) {
            int left_sqr = nums[left] * nums[left];
            int right_sqr = nums[right] * nums[right];

            if(left_sqr > right_sqr) {
                res[last--] = left_sqr;
                left++;
            } else {
                res[last--] = right_sqr;
                right--;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums{};
    Solution obj;
    vector<int> res = obj.sortedSquares(nums);
    return 0;
}