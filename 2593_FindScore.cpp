#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;       

class Solution 
{
    public:
        
        long long findScore(vector<int>& nums) 
        {
            vector<vector<int>> sorted(nums.size(),vector<int>(2));
            long long ans = 0;

            for(int i = 0; i <nums.size(); i++)
            {
                sorted[i][0] = nums[i];
                sorted[i][1] = i;
            }
            sort(sorted.begin(),sorted.end());

            vector<bool>marked(nums.size(),false);

            for(int i = 0; i < nums.size(); i++)
            {
                int num = sorted[i][0];
                int idx = sorted[i][1];

                if(!marked[idx])
                {
                    ans += nums[idx];
                    marked[idx] = true;

                    if(idx - 1 >= 0) {
                        marked[idx - 1] = true;
                    }
                    if(idx + 1 <= nums.size()-1) {
                        marked[idx + 1] = true;
                    }
                }
            }
            return ans;
        }
};

int main()
{
    vector<int> nums{2,3,5,1,3,2};
    Solution obj;
    int ret = obj.findScore(nums);

    cout<<ret<<"\n";

    return 0;
}