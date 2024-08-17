#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int i = 0,j = nums.size()-1;
        int n = -1,m = -1;
        while(i <= j)
        {
            if(m == -1)
            {
                if(nums[i] == target)  m = i;
                if(m == -1) i++;
            }
            if(n == -1)   
            {
                if(nums[j] == target)  n = j;
                if(n == -1) j--;
            }
            if(m != -1 && n != -1) break;
        }
        return {m,n};
    }
};

int main()
{
    // vector<data_type> array_name[array_size];  
    vector<int> vect{ 10, 20, 30 };
    int *ret = NULL;

    Solution obj;
    obj.searchRange(vect,10);

    return 0;
}