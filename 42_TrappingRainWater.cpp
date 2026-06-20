#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left_max = height[0];
        int right_max = height[n - 1];
        int left = 0, right = n - 1;;
        int ans = 0;

        while(left < right) {
            if(left_max < right_max) {
                left++;
                left_max = max(left_max,height[left]);
                ans += (left_max - height[left]);
            } else {
                right--;
                right_max = max(right_max, height[right]);
                ans += (right_max - height[right]);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = solution.trap(height);
    cout << "Trapped water: " << result << endl; // Output: 6
    return 0;
}