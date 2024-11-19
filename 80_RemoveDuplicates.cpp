#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i =0;
        for(auto ele : nums)
        {
            if(i==0 || i==1 || nums[i-2] != ele)
            {
                nums[i] = ele;
                i++;
            }
        }
    return i ;
    }
    int removeDuplicates1(vector<int>& v) 
    {
            int n = v.size();
            if(n < 3) return n;
            int a = 2;

            for(int i = 2; i < n; i++) 
            {
                if(v[i] != v[a-2]) 
                {
                    v[a] = v[i];
                    a++;
                }
            }
            return a;
        }
};

int main()
{
    vector<int> vect{0,0,1,1,1,1,2,3,3};
    int *ret = NULL;

    Solution obj;
    obj.removeDuplicates(vect);

    return 0;
}