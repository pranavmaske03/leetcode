#include<iostream>
using namespace std;

class Solution {
    public:
        bool isArraySpecial(vector<int>& nums) 
        {
            for(int i = 1; i < nums.size(); i++)    
            {
                if(nums[i]%2 == nums[i-1]%2) {
                    return false;
                }
            }
            return true;
        }
};

int main()
{


    return 0;
}