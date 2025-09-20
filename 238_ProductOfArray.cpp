#include<iostream>
using namespace std;

class Solution 
{
    public:
        vector<int> productExceptSelf(vector<int>& nums) 
        {
            vector<int> answer(nums.size(),1);

            int left = 1;
            for(int i = 0; i < nums.size(); i++) 
            {
                answer[i] *= left;
                left *= nums[i];
            }
            int right = 1;
            for(int i = nums.size()-1; i >= 0; i--)
            {
                answer[i] *= right;
                right *= nums[i];
            }
            return answer;
        }
};

int main()
{

    return 0;
}