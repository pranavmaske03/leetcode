#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        // approach 1
        long long countFairPairs(vector<int>& nums, int lower, int upper) 
        {
            sort(nums.begin(), nums.end());  

            int n = nums.size();
            long long totalCount = 0;

            for(int i = 0; i < n; i++)
            {
                int left = -1, right = -1;
                int start = i + 1,end = n -1;

                while(start <= end) {
                    int mid = start + (end - start) /  2;

                    if(nums[mid] >= lower - nums[i]) {
                        left = mid;
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }

                start = i + 1,end = n-1;
                while(start <= end) {
                    int mid = start + (end - start) /  2;

                    if(nums[mid] <= upper - nums[i]) {
                        right = mid;
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
                if(right != -1 && left != -1 && left <= right) {
                    totalCount += (right - left + 1);
                }
            }
            return totalCount;
        }
        // approach 2
        long long countFairPairs1(vector<int>& nums, int lower, int upper) {
            long long res = 0;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size() - 1; i++) {
                int minReq = lower - nums[i];
                int maxReq = upper - nums[i];

                auto low = lower_bound(nums.begin() + i + 1, nums.end(), minReq);
                auto high = upper_bound(nums.begin() + i + 1, nums.end(), maxReq);

                res += (high - low);
            }
            return res;
        }
        // approach 3
        long long solve(vector<int>& nums, long long bound)
        {   
            long long res = 0;
            for(int i = 0, j = nums.size() - 1; i < j; i++) {
                while(i < j && nums[i] + nums[j] > bound) j--;
                res += (j - i);
            }
            return res;
        }
        long long _solve(vector<int>& nums, long long bound)
        {   
            int left = 0, right = nums.size()-1;
            long long count = 0;
            while(left < right) {
                if(nums[left] + nums[right] <= bound) {
                    count += right - left;
                    left++;
                } else right--;
            }
            count += (right - left);
            
            return count;
        }
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(), nums.end());
            return solve(nums, upper) - solve(nums, lower - 1);
        }
};


int main()
{

    return 0;
}