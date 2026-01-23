#include<iostream>
#include<unordered_set>
using namespace std;

class Solution 
{
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        unordered_set<int> st;
        long long max_sum = 0, curr_sum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            while (st.find(nums[right]) != st.end())
            {
                st.erase(nums[left]);
                curr_sum -= nums[left];
                left++;
            }

            st.insert(nums[right]);
            curr_sum += nums[right];

            if (right - left + 1 == k)
            {
                max_sum = max(max_sum, curr_sum);
                st.erase(nums[left]);
                curr_sum -= nums[left];
                left++;
            }
        }

        return max_sum;
    }
};

int main()
{
    return 0;
}