#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> sortArrayByParity(vector<int>& nums) 
        {
            int start = 0,last = nums.size()-1;
            vector<int> result(nums.size());

            for(int i = 0; i < nums.size(); i++) {
                if(nums[i]%2) {
                    result[last--] = nums[i];
                } else {
                    result[start++] = nums[i];
                }
            }
            return result;
        }
};

int main()
{

    return 0;
}