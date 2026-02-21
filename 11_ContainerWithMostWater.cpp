#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while(left < right) {
            if(height[left] < height[right]) {
                max_area = max(max_area, height[left] * (right - left));
                left++;
            } else {
                max_area = max(max_area, height[right] * (right - left));
                right--;
            }
        }
        return max_area;
    }
};

int main()
{
    return 0;
}