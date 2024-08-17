#include<iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int count = 0,max = 0;
        for(int i = 0; i < nums.size(); i++)
        {   
            if(nums[i] == 1){
                count++;
            }
            else{
                if(max < count) max = count;
                count = 0;
            }
        }
        return max > count ? max : count;
    }
};

int main()
{

    return 0;
}