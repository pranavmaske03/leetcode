#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,vector<vector<int>>& queries) 
    {
        vector<bool> ans(queries.size(), false);
        vector<int> prefix(nums.size(), 0);
        prefix[0] = 0;

        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] % 2 == nums[i - 1] % 2) 
            {
                // new violative index found
                prefix[i] = prefix[i - 1] + 1;
            } 
            else 
            {
                prefix[i] = prefix[i - 1];
            }
        }
        for (int i = 0; i < queries.size(); i++) 
        {
            vector<int> query = queries[i];
            int start = query[0];
            int end = query[1];
            ans[i] = prefix[end] - prefix[start] == 0;
        }
        return ans;
    }
    vector<bool> isArraySpecial1(vector<int>& nums,vector<vector<int>>& queries) 
    {
        int n = nums.size();
        vector<int> maxReach(n);
        int end = 0;

        // Step 1: Compute the maximum reachable index for each starting index
        for (int start = 0; start < n; start++) 
        {
            // Ensure 'end' always starts from the current index or beyond
            end = max(end, start);

            // Expand 'end' as long as adjacent elements have different parity
            while (end < n - 1 && nums[end] % 2 != nums[end + 1] % 2) {
                ++end;
            }

            // Store the farthest index reachable from 'start'
            maxReach[start] = end;
        }

        vector<bool> ans(queries.size());

        // Step 2: Answer each query based on precomputed 'maxReach'
        for (int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            int start = query[0];
            int end = query[1];

            // Check if the query range [start, end] lies within the max
            // reachable range
            ans[i] = end <= maxReach[start];
        }

        return ans;
    }
};

int main()
{
    vector<int>  nums = {1,2,3,4,6,9,4,1,8};
    vector<vector<int>> queries = {{0,2},{2,4}};

    Solution obj;
    obj.isArraySpecial(nums,queries);

    return 0;
}