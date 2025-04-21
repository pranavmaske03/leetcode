#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int findMiddleIndex(vector<int>& nums) {
            int left_sum = 0;
            int total_sum = 0,middle_index = -1;

            for(int i = 0; i < nums.size(); i++) {
                total_sum += nums[i];
            }

            for(int i = 0; i < nums.size(); i++) {
                if(left_sum == total_sum - left_sum - nums[i]) {
                    middle_index = i;
                    break;
                }
                left_sum += nums[i];
            }
            return middle_index;
        }
};

int main()
{

    return 0;
}