#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sum = INT_MIN, sum = 0;
        int left = 0;
        
        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            if(right - left  + 1 == k) {
                max_sum = max(max_sum, sum);
                sum -= nums[left++];
            }
        }
        return (double) max_sum / k;
    }
};

int main() {
    
    return 0;
}