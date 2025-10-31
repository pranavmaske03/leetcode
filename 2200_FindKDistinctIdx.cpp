#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
        {
            vector<int> keys;
            for (int i = 0; i < nums.size(); i++) 
            {
                if (nums[i] == key) {
                    keys.push_back(i);
                }
            }

            vector<int> ans;
            int idx = 0;
            for (int i = 0; i < nums.size(); i++) 
            {
                if(idx < keys.size() - 1 && i > k + keys[idx]) idx++;
                if(abs(i - keys[idx]) <= k) ans.push_back(i);
            }
            return ans;
        }
};


int main()
{

    return 0;
}